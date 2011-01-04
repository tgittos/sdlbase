#include "GLDraw.h"

namespace GLDraw
{
	void SetColour(GLfloat p_r, GLfloat p_g, GLfloat p_b)
	{
		glColor3f(p_r, p_g, p_b);	
	}

	void Square(GLfloat p_x, GLfloat p_y, GLfloat p_w, GLfloat p_h)
	{
		glBegin(GL_QUADS);
	        	glVertex3f(p_x, p_y, 0);
        		glVertex3f(p_x + p_w, p_y, 0);
	        	glVertex3f(p_x + p_w, p_y + p_h, 0);
        		glVertex3f(p_x, p_y + p_h, 0);
		glEnd();
	}
};
