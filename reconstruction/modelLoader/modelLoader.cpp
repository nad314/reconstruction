#include <main/main.h>

bool ModelLoader::loadPLYBin(const char* path, core::buffer<vec3>& vecs) {
	std::ifstream file(path, std::ios::binary);
	if (file.is_open()) {
		std::string line;
		std::streampos pos;
		char first[256];
		char second[256];
		char third[256];
		while (std::getline(file, line)) {
			core::Debug::print("%s\n", line.c_str());
			if (line.find("end_header") != std::string::npos) {
				pos = file.tellg();
				break;
			}

			sscanf(line.c_str(), "%s %s %s", first, second, third);
			if (strcmp(first, "format") == 0) {
				core::Debug::log("PLY format: %s\n", second);
			}

			if (file.eof()) return 0;
		}
	}
	else return 0;
	file.close();
	return 1;
}