#include "SDL_D3D_Window.h"

bool SDL_D3D_Window::init()
{
	/*
	LPDirect3D9             Direct3D_object;    //used to create a direct 3d device
   LPDirect3DDEVICE9       Direct3D_device;    //basic rendering object
   D3DPRESENT_PARAMETERS   present_parameters; //stores the important attributes and 
   D3DXMATRIX              projection_matrix;  //   properties your Direct3D_device will have
   LPDirect3DVERTEXBUFFER9 tri_buffer = NULL;  //data buffer which the Direct3D_device can draw from
   VOID* pData;                                //pointer to beginning of vertex buffer
   //actual data to be fed to the vertex buffer
   D3DVERTEX aTriangle[ ] = {{-2.0f,1.0f,10.0f,0xffff0000},
                             {-3.0f,-1.0f,10.0f,0xff00ff00},
                             {-1.0f,-1.0f,10.0f,0xff0000ff}};
	*/
	m_background = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_DEPTH, SDL_RESIZABLE);
	LPDIRECT3D9 d3d_object = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d_object == NULL)
	{
		//Error
		return false;
	}

	//Set parameters

	//Get current display mode
	D3DDISPLAYMODE d3ddm;
	d3d_object->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

	SDL_SysWMinfo sysInfo;
	SDL_VERSION(&sysInfo.version);
	HWND window;
	if (SDL_GetWMInfo(&sysInfo) <= 0)
	{
		char* errorMsg = SDL_GetError();
		return false;
	}
	window = sysInfo.window;

	D3DPRESENT_PARAMETERS present_parameters;
	ZeroMemory(&present_parameters, sizeof(present_parameters));
	present_parameters.Windowed = true;
	present_parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	present_parameters.EnableAutoDepthStencil = true;
	present_parameters.AutoDepthStencilFormat = D3DFMT_D16;
	present_parameters.hDeviceWindow = window;
	present_parameters.BackBufferWidth = SCREEN_WIDTH;
	present_parameters.BackBufferHeight = SCREEN_HEIGHT;
	present_parameters.BackBufferFormat = d3ddm.Format;

	//Create the Direct3D Device
	HRESULT hres = d3d_object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &present_parameters, &d3d_device);
	if (FAILED(hres))
	{
		//Error
		const char* errorMsg = DXGetErrorDescription(hres);
		return false;
	}

	//Set up the device for rendering
	D3DXMATRIX projection_matrix;
	D3DXMatrixPerspectiveFovLH(&projection_matrix, D3DX_PI / 4.0f,(float) SCREEN_WIDTH/SCREEN_HEIGHT,1, 1000);
	d3d_device->SetTransform(D3DTS_PROJECTION,&projection_matrix); //Set the projection matrix
	d3d_device->SetRenderState(D3DRS_AMBIENT,RGB(255,255,255)); //Set background?

	d3d_device->SetRenderState(D3DRS_LIGHTING,false); //No lighting

	d3d_device->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE); //No culling

	d3d_device->SetRenderState(D3DRS_ZENABLE,D3DZB_TRUE);
	d3d_device->SetFVF((D3DFVF_XYZ | D3DFVF_DIFFUSE));

	//Set up the vertex buffer and data to render
	VOID* pData; 
	tri_buffer = NULL;
	D3DVERTEX aTriangle[ ] = {{-2.0f,1.0f,10.0f,0xffff0000},
                             {-3.0f,-1.0f,10.0f,0xff00ff00},
                             {-1.0f,-1.0f,10.0f,0xff0000ff}};
	d3d_device->CreateVertexBuffer(sizeof(aTriangle),D3DUSAGE_WRITEONLY,
                                    (D3DFVF_XYZ | D3DFVF_DIFFUSE),
                                    D3DPOOL_MANAGED,&tri_buffer,NULL);

	tri_buffer->Lock(0,sizeof(pData),(void**)&pData,0);
	memcpy(pData,aTriangle,sizeof(aTriangle));
	tri_buffer->Unlock();

	return true;
}

void SDL_D3D_Window::render()
{
	d3d_device->Clear(0,NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                             D3DCOLOR_XRGB(0,0,0),1.0f,0);
	d3d_device->BeginScene();

	onDraw();

	d3d_device->EndScene();
	d3d_device->Present(NULL,NULL,NULL,NULL);
}