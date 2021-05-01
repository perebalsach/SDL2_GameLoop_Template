#include "game.h"

Game::Game()
{
	m_running = false;
	m_input = new Input();
	renderer = new Renderer();
}

void Game::Init(int width, int height)
{
	bool initSucced = false;
	m_running = true;
	if (!renderer->Init(width, height))
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
	renderer->Destroy();
}
