#pragma once

class ModelLoader {
private:
public:
	static bool loadPLYBin(const char* path, core::buffer<vec3>& vecs);
};

