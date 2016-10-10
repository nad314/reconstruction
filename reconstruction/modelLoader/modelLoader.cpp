#include <main/main.h>

bool ModelLoader::loadPLYBin(const char* path, core::buffer<vec3>& vecs) {
	std::ifstream file(path, std::ios::binary);
	int bpv = 0; //bytes per vertex
	int x_at;
	std::streampos pos;
	size_t vcount = 0;
	try {
		if (file.is_open()) {
			std::string line;
			char first[256];
			char second[256];
			char third[256];

			int state = 0; //reading state
			while (std::getline(file, line)) {
				core::Debug::print("%s\n", line.c_str());
				if (line.find("end_header") != std::string::npos) {
					pos = file.tellg();
					break;
				}

				sscanf(line.c_str(), "%s %s %s", first, second, third);
				if (strcmp(first, "format") == 0) {
					core::Debug::log("PLY format: %s\n", second);
					if (strstr(second, "binary"))
						core::Debug::log("Reading Binary PLY file\n");
					else break;
					continue;
				}

				if (strcmp(first, "element") == 0) {
					if (state & 1 && state & 2)
						core::Debug::log("Vertex size: %dbytes\n", bpv);
					state = 1;
					if (strcmp(second, "vertex") == 0) {
						state |= 2;
						int count;
						if (sscanf(third, "%d", &count) != 1) {
							core::Debug::log("Error reading vertex count\n");
							break;
						}
						else {
							vecs.reserve(count);
							vcount = count;
							bpv = 0;
						}
					}
					else if (strcmp(second, "face") == 0) {
						state |= 4;
					}
					continue;
				}

				if (strcmp(first, "property") == 0) {
					if (!(state & 1) || !(state & 2))
						continue;

					if (strcmp(third, "x") == 0)
						x_at = bpv;

					if (strcmp(second, "float32") == 0) bpv += 4;
					else if (strcmp(second, "float") == 0) bpv += 4;
					else if (strcmp(second, "uint8") == 0) bpv += 1;
					else if (strcmp(second, "uchar") == 0) bpv += 1;
					else {
						core::Debug::log("ERROR: unknown variable format\n");
						throw 1;
						break;
					}
				}

				if (file.eof()) throw 2;
			}
		}
		else return 0;
		file.seekg(pos, std::ios::ios_base::beg);

		char* block = new char[bpv];
		for (size_t i = 0; i < vcount; ++i) {
			if (file.read(block, bpv).fail()) {
				delete[] block;
				throw 4;
			}
			vecs.push_back(*((vec3*)(block+x_at)));
		}
		delete[] block;
	}
	catch (int e) {
		core::Debug::log("Exception occured (%d)\n", e);
	}

	core::Debug::log("Bytes per vertex: %d\n", bpv);

	if (file.is_open())
		file.close();
	return 1;
}
