#include "input.h"

Input::Input()
{
    m_isRunning = true;
}

bool Input::GetInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT: {
            m_isRunning = false;
            return false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                m_isRunning = false;
                return false;
            }
        }
        default: {
            break;
        }
    }
    return true;
}
