#ifndef GLSL_H
#define GLSL_H
#include <GL/glew.h>
#include <string>

class GLSL
{
public:
	GLSL();
	virtual ~GLSL();
	GLSL(const GLSL&) = delete;
	GLSL& operator=(const GLSL&) = delete;
	GLSL(GLSL&&) = delete;
	GLSL& operator=(GLSL&&) = delete;

	virtual void build() = 0;
	const GLuint& getProgram() const { return program_; }

protected:
	void compile(const GLenum& shaderType, const std::string& sourceCode);
	void link();

	GLuint program_;
	GLuint shader_;
};
#endif // GLSL_H