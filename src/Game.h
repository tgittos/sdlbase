#ifndef GAME_H
#define GAME_H

//#include <SDL_GL_Window.h>
//#include <GLDraw.h>
#include <SDL_D3D_Window.h>

class Game : public SDL_D3D_Window//SDL_GL_Window
{
	public:
		Game();
		virtual void onEvent(SDL_Event* e);
		virtual void onDraw();	
};

#endif
