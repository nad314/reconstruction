#include <main/main.h>

Storage::Storage() {
	core::buffer<vec3> vecs;
	core::Path::pushDir();
	core::Path::goHome();
	core::Path::cd("../data/");
	try {
		if (!shader.load("shaders/default/vertex.glsl", "shaders/default/fragment.glsl", "fragColor"))
			throw 1;
		if (!ModelLoader::loadPLYBin("MP-jarbol.ply", vecs))
			throw 2;
		else {
			core::Debug::print("Loaded %d vertices\n", vecs.count());
			cloud.vecs = vecs;
			glCloud.make(cloud);
			glCloud.attach(shader, "pos");
		}
	}
	catch (int e) {
		switch (e) {
		case 1: core::Debug::log("Exception: Failed to load shader\n"); break;
		case 2: core::Debug::log("Exception: Failed to load PLY\n"); break;
		default: core::Debug::log("Unkown Exception at Storage()\n"); break;
		}
	}
	core::Path::popDir();
}
