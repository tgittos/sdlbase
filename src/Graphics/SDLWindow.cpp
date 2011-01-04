//Header for this file
#include "SDLWindow.h"

SDLWindow::SDLWindow()
{
	m_running = true;

	//Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//There was a problem initialising SDL
		//Report an error or something
	}
}

void SDLWindow::set_title(char* p_wTitle, char* p_iTitle)
{
	 m_wTitle = p_wTitle; 
	 m_iTitle = p_iTitle;
	 SDL_WM_SetCaption(m_wTitle, m_iTitle);
}

int SDLWindow::run()
{
	SDL_Event e;
	while (m_running)
	{
		while (SDL_PollEvent(&e))
		{
			onEvent(&e);
		}
		render();		
	}

	return 0;
}

void SDLWindow::quit()
{
	SDL_FreeSurface(m_background);
	SDL_Quit();
}
