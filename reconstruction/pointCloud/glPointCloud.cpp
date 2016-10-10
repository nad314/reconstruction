#include <main/main.h>

namespace core {
	glPointCloud& glPointCloud::dispose() {
		if (glExt::isVertexArray(vao))
			glExt::deleteVertexArrays(1, &vao);
		if (glExt::isBuffer(buffer[0]))
			glExt::deleteBuffers(nbuf, buffer);
		vao = 0;
		memset(buffer, 0, sizeof(uint)*nbuf);
		count = 0;
		return *this;
	}

	bool glPointCloud::make(pointCloud& cloud) {
		dispose();
		try {
			glExt::genBuffers(nbuf, buffer);
			if (!glExt::isBuffer(buffer[0]))
				throw 1;
			glExt::genVertexArrays(1, &vao);
			if (!glExt::isVertexArray(vao))
				throw 2;

			glExt::bindVertexArray(0);
			glExt::bindBuffer(GL_ARRAY_BUFFER, buffer[0]);
			glExt::bufferData(GL_ARRAY_BUFFER, cloud.vecs.count() * sizeof(vec3), cloud.vecs, GL_STATIC_DRAW);
			count = cloud.vecs.count();
		}
		catch (int e) {
			core::Debug::log("Exceprtion %d while making buffers\n", e);
			dispose();
			return 0;
		}
		return 1;
	}

	bool glPointCloud::attach(glShader& shader, const char* vname) {
		glGetError(); //empty error
		try {
			glExt::bindVertexArray(vao);
			glExt::bindBuffer(GL_ARRAY_BUFFER, buffer[0]);
			int index = glExt::getAttribLocation(shader, vname);
			glExt::enableVertexAttribArray(index);
			if (glGetError()) throw 1;
			glExt::vertexAttribPointer(index, 3, GL_FLOAT, 0, 0, NULL);
			if (glGetError()) throw 2;
		}
		catch (int e) {
			core::Debug::print("Exception %d occured while trying to attach to shader\n", e);
			return 0;
		}
		return 1;
	}

	const glPointCloud& glPointCloud::draw() const {
		glExt::bindVertexArray(vao);
		glDrawArrays(GL_POINTS, 0, count);
		return *this;
	}
}
