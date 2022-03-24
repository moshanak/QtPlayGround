#ifndef GLSLMANAGER_H
#define GLSLMANAGER_H
#include "GLSL.h"
#include <memory>
#include <unordered_map>


enum class GLSLType {
	passthrough
};

class GLSLManager {
public:
	static GLSLManager& getInstance();
	GLuint getProgramHandle(GLSLType type);

private:
	GLSLManager();
	std::unordered_map<GLSLType, std::unique_ptr<GLSL>> glslHashTable_;
};
#endif //GLSLMANAGER_H