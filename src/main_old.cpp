#include <stdio.h>
#include <SDL.h>
#include <iostream>
#include "renderer.h"

bool init();
bool loadMedia();
void killSDL();
SDL_Surface loadSurface(std::string path);

SDL_Surface* winSurface;
SDL_Window* win;
SDL_Surface* image;

/*
int main(int argc, char* argv[])
{
	if (!Renderer::Init()) return 1;
	if (!loadMedia()) return 1;
	
	bool quit = false;
	SDL_Event evt;

	while (!quit)
	{
		while (SDL_PollEvent(&evt) != 0)
		{
			if (evt.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		// Apply image	
		SDL_BlitSurface(image, NULL, winSurface, NULL);

		// Update the surface
		SDL_UpdateWindowSurface(win);
	}

	killSDL();

	return 0;
}
*/
void killSDL()
{
	SDL_FreeSurface(image);
	image = NULL;

	// Shutdown everything
	SDL_DestroyWindow(win);
	win = NULL;
	winSurface = NULL;

	SDL_Quit();
}

SDL_Surface loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s SDL Error> %s\n", path.c_str(), SDL_GetError());
	}
	return SDL_Surface();
}

bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Error initializing SDL %s", SDL_GetError());
		return false;
	}

	win = SDL_CreateWindow("Title Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if (!win)
	{
		printf("Error creating SDL Window, %s", SDL_GetError());
		return false;
	}
	winSurface = SDL_GetWindowSurface(win);
	
	// Draw
	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 90, 120));

	return true;
}

bool loadMedia()
{
	image = SDL_LoadBMP("..\\C_02\\images\\image.bmp");
	if (image == NULL)
	{
		printf("Error Loading the BMP image, %s", SDL_GetError());
		return false;
	}
	return true;
}