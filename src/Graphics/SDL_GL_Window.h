#ifndef SDL_GL_WINDOW_H
#define SDL_GL_WINDOW_H

#ifdef WIN32
	#include <Windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include "SDLWindow.h"

class SDL_GL_Window : public SDLWindow
{
	protected:
		void render();
	public:
		bool init();
};

#endif
