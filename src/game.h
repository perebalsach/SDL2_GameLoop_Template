#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "window.h"

class Game
{
public:
	Game();

	void Init(int width, int height);

	void HandleInput();
	void Update();
	void Render();

	bool IsRunning();
	void Destroy();

private:
	bool m_running;
	Input* m_input;
	Window* window;
};
#endif // !GAME_H
