#ifndef GLSLPASSTHROUGH_H
#define GLSLPASSTHROUGH_H
#include "GLSL.h"

class GLSLPassthrough : public GLSL
{
public:
	void build() final;
};
#endif // GLSLPASSTHROUGH_H