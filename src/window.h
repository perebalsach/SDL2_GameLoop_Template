#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <stdio.h>

class Window
{
public:
	Window();

	bool Init(int width, int height);
	void Destroy();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
#endif // !WINDOW_H
