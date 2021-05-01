#include <stdio.h>
#include <SDL.h>
#include <iostream>

#include "game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	
	game->Init(800, 600);

	while (game->IsRunning())
	{
		game->HandleInput();
		game->Update();
		game->Render();
		printf("Running \n");
	}

	game->Destroy();
	printf("End Game \n");
	return 0;
}