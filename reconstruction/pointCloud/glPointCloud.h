#pragma once

namespace core {
	class glPointCloud {
	private:
		static const int nbuf = 2;
		uint buffer[nbuf];
		uint vao;
		int count;
		
	public:
		glPointCloud& dispose();
		glPointCloud();
		~glPointCloud() { dispose(); }
		bool make(pointCloud& cloud);
		bool attach(glShader& shader, const char* vname);

		const glPointCloud& draw() const;
	};
}
