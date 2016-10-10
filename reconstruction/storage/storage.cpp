#include <main/main.h>

Storage::Storage() {
	core::buffer<vec3> vecs;
	core::Path::pushDir();
	core::Path::goHome();
	core::Path::cd("../data/");
	if (!ModelLoader::loadPLYBin("MP-jarbol.ply", vecs))
		printf("Couldn't load PLY file\n");
	else {
		core::Debug::print("Loaded %d vertices\n", vecs.count());
	}
	core::Path::popDir();
}
