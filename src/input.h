#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class Input
{
public:
	Input();

	bool GetInput();

private:
	bool m_isRunning;
};

#endif // !INPUT_H
