#ifndef SDL_D3D_WINDOW_H
#define SDL_D3D_WINDOW_H

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <DxErr.h>
#include "SDLWindow.h"

struct D3DVERTEX
{
	float fX, fY, fZ;
	unsigned int dwColour;
};

class SDL_D3D_Window : public SDLWindow
{
	protected:
		LPDIRECT3DDEVICE9 d3d_device;
		LPDIRECT3DVERTEXBUFFER9 tri_buffer;
		void render();
	public:
		bool init();
};

#endif