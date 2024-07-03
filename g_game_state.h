#ifndef G_GAME_STATE_H
#define G_GAME_STATE_H

#define SDL_MAIN_HANDLED

#ifdef _WIN64
#include "libs/win_sdl2/include/SDL2/SDL.h"
#elif __APPLE__
#include "libs/macos_sdl2/include/SDL2/SDL.h"
#endif

#include "typedefs.h"

typedef struct _game_state
{
    unsigned int scrn_w;
    unsigned int scrn_h;
    double target_fps;
    double target_frame_time;
    double delta_time;
    bool is_running;
    bool is_paused;
    bool is_fps_capped;
    bool state_show_map;
    bool is_debug_mode;
} game_state_t;

game_state_t G_Init(const unsigned int scrnw, const unsigned int scrnh, int target_fps);
void G_FrameStart();
void G_FrameEnd(game_state_t *state);

#endif /* G_GAME_STATE_H */
