#include "Game.h"

Game::Game()
{
	set_title("My Game", "My Game Icon");
}

void Game::onEvent(SDL_Event* e)
{
	switch (e->type)
	{
		case SDL_QUIT:
			m_running = false;
			break;
	}
}

void Game::onDraw()
{
	//Open GL stuff
	//GLDraw::SetColour(0, 0.5, 0.5);
	//GLDraw::Square(10, 10, 100, 100);

	//DirectX stuff
	d3d_device->SetStreamSource(0,tri_buffer,0,sizeof(D3DVERTEX));
	d3d_device->DrawPrimitive(D3DPT_TRIANGLELIST,0,1);
}
