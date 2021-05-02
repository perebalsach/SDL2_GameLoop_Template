#include "game.h"

Game::Game()
{
	m_running = false;
	m_input = new Input();
	window = new Window();
}

void Game::Init(int width, int height)
{
	bool initSucced = false;
	m_running = true;

	if (!window->Init(width, height))
	{
		printf("Game::Init - Error initilaizing the renderer");
	}
}

void Game::HandleInput()
{
	m_running = m_input->GetInput();
}

void Game::Update()
{
}

void Game::Render()
{
}

bool Game::IsRunning()
{
	return m_running;
}

void Game::Destroy()
{
	window->Destroy();
}
