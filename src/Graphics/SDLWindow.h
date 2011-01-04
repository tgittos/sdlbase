#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>

// Abstract SDLWindow class
class SDLWindow
{
	protected:
		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 600;
		static const int COLOUR_DEPTH = 32;
		char* m_wTitle; //Window title
		char* m_iTitle; //Icon title
		bool m_running;
		SDL_Surface* m_background;
		virtual void render() = 0;

	public:
		SDLWindow();
		virtual bool init() = 0;
		void set_title(char* p_wTitle, char* p_iTitle);
		int run();
		virtual void onEvent(SDL_Event* e) = 0;
		virtual void onDraw() = 0;
		void quit();	
};

#endif
