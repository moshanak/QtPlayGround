#include "ActorTriangleTestRenderer.h"
#include "GLSLManager.h"
#include <vector>
#include <array>

ActorTriangleTestRenderer::ActorTriangleTestRenderer(const int& actorID)
	:ActorBaseRenderer(actorID)
{
}

void ActorTriangleTestRenderer::draw()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	std::vector<float> coords{ 0.5f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f, -0.5f, 0.0f, 0.0f };

	GLuint coordinateBuffer_ = 0;
	glGenBuffers(1, &coordinateBuffer_);
	glBindBuffer(GL_ARRAY_BUFFER, coordinateBuffer_);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * coords.size(), coords.data(), GL_STATIC_DRAW);

	glEnable(GL_DEPTH_TEST);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, coordinateBuffer_);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	const GLuint& program = GLSLManager::getInstance().getProgramHandle(GLSLType::passthrough);

	const std::array<float, 4> color = {1.0f, 1.0f, 0.0f, 1.0f};
	const GLuint partColorLocation = glGetUniformLocation(program, "OutputColor");
	glProgramUniform4fv(program, partColorLocation, 1, color.data());

	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glUseProgram(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);

	glDeleteBuffers(1, &coordinateBuffer_);
	coordinateBuffer_ = 0;
}
