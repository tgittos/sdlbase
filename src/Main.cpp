#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game window;
	if(!window.init())
	{
		std::cout << "Error starting window";
	} else
	{
		window.run();
		window.quit();
	}
	return 0;
}
