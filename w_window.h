#ifndef W_WINDOW_H
#define W_WINDOW_H

#define SDL_MAIN_HANDLED

#ifdef _WIN64
#include "libs/win_sdl2/include/SDL2/SDL.h"
#elif __APPLE__
#include "libs/macos_sdl2/include/SDL2/SDL.h"
#endif

void W_Init(const unsigned int winw, const unsigned int winh);
void W_Shutdown();
SDL_Window* W_Get();

#endif /* W_WINDOW_H */
