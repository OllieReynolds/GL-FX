#include "drawable.hpp"

Drawable::Drawable(float* vertices, float* uvs, float* normals,
				   unsigned short* indices, GLenum usage) {
	assert(vertices && uvs);
					   
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(4, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 36, vertices, usage); 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
 
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 36, uvs, usage);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	if (normals) {
		glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 36, normals, usage);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(2);
	}

	if (indices) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[3]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * 36, indices, usage);
		glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &elements);
	}
}

Drawable::~Drawable() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	 
	glBindBuffer(GL_ARRAY_BUFFER, 0);
 
	glDeleteBuffers(4, vbo);
 
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vao);
}