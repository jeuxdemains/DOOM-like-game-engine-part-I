#include "w_window.h"

SDL_Window *sdl_window = NULL;

void W_Init(const unsigned int winw, const unsigned int winh)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    sdl_window = SDL_CreateWindow(
        "Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        winw,
        winh,
        SDL_WINDOW_SHOWN
    );
}

void W_Shutdown()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

SDL_Window* W_Get()
{
    return sdl_window;
}