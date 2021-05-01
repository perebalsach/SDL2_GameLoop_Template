#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdio.h>

class Renderer
{
public:
	Renderer();

	void Update(float deltaTime);
	bool Init(int height, int width);
	void Destroy();

private:
	SDL_Window* m_window;
	SDL_Surface* m_winSurface;
	SDL_Renderer* m_renderer;
};
#endif // !RENDERER_H
