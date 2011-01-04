#ifndef GLDRAW_H
#define GLDRAW_H

#ifdef WIN32
	#include <Windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

namespace GLDraw
{
	void SetColour(GLfloat p_r, GLfloat p_g, GLfloat p_b);
	void Square(GLfloat p_x, GLfloat p_y, GLfloat p_w, GLfloat p_h);
}

#endif