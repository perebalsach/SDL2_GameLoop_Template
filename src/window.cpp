#include "Window.h"

Window::Window()
{
	m_window = NULL;
	m_renderer = NULL;
}

bool Window::Init(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error initializing SDL %s", SDL_GetError());
		return false;
	}

	m_window = SDL_CreateWindow(
		"Game Engine v0.1",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_ALWAYS_ON_TOP
	);

	if (!m_window)
	{
		printf("Error creating SDL Window, %s", SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (!m_renderer)
	{
		printf("Error creating SDL renderer. %s", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(m_renderer, 21, 21, 21, 255);
	SDL_RenderClear(m_renderer);

	SDL_RenderPresent(m_renderer);

	return true;
}

void Window::Destroy()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}
