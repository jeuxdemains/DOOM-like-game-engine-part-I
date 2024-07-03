#include "k_keyboard.h"

keymap_t keymap;
keystates_t keystates;
const double MOV_SPEED = 150.0;
const double ELEVATION_SPEED = 500 * 100;
const double ROT_SPEED = 4;

void K_InitKeymap()
{
    keymap.forward = SDL_SCANCODE_W;
    keymap.backward = SDL_SCANCODE_S;
    keymap.left = SDL_SCANCODE_A;
    keymap.right = SDL_SCANCODE_D;
    keymap.quit = SDL_SCANCODE_ESCAPE;
    keymap.strafe_left = SDL_SCANCODE_Q;
    keymap.strafe_right = SDL_SCANCODE_E;
    keymap.up = SDL_SCANCODE_SPACE;
    keymap.down = SDL_SCANCODE_LCTRL;
    keymap.toggle_map = SDL_SCANCODE_M;
    keymap.debug_mode = SDL_SCANCODE_O;

    keystates.forward = false;
    keystates.backward = false;
    keystates.left = false;
    keystates.right = false;
    keystates.s_left = false;
    keystates.s_right = false;
    keystates.up = false;
    keystates.down = false;
    keystates.map_state = false;
    keystates.is_debug = false;
}

void K_HandleEvents(game_state_t *game_state, player_t *player)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_KEYDOWN:
        K_HandleRealtimeKeys(event.key.keysym.scancode, KEY_STATE_DOWN);
        game_state->state_show_map = keystates.map_state;

        if (event.key.keysym.scancode == keymap.quit)
            game_state->is_running = false;

        if (event.key.keysym.scancode == keymap.debug_mode)
            game_state->is_debug_mode = !game_state->is_debug_mode;

        break;
    
    case SDL_KEYUP:
        K_HandleRealtimeKeys(event.key.keysym.scancode, KEY_STATE_UP);
        break;

    case SDL_QUIT:
        game_state->is_running = false;
        break;
    default:
        break;
    }

    K_ProcessKeyStates(player, game_state->delta_time);
}

void K_ProcessKeyStates(player_t *player, double delta_time)
{
    if (keystates.forward)
    {
        player->position.x += MOV_SPEED * cos(player->dir_angle) * delta_time;
        player->position.y += MOV_SPEED * sin(player->dir_angle) * delta_time;
    }
    else if (keystates.backward)
    {
        player->position.x -= MOV_SPEED * cos(player->dir_angle) * delta_time;
        player->position.y -= MOV_SPEED * sin(player->dir_angle) * delta_time;
    }

    if (keystates.left)
    {
        player->dir_angle += ROT_SPEED * delta_time;
    }
    else if (keystates.right)
    {
        player->dir_angle -= ROT_SPEED * delta_time;
    }

    if (keystates.s_left)
    {
        player->position.x += MOV_SPEED * cos(player->dir_angle + M_PI / 2) * delta_time;
        player->position.y += MOV_SPEED * sin(player->dir_angle + M_PI / 2) * delta_time;
    }
    else if (keystates.s_right)
    {
        player->position.x -= MOV_SPEED * cos(player->dir_angle + M_PI / 2) * delta_time;
        player->position.y -= MOV_SPEED * sin(player->dir_angle + M_PI / 2) * delta_time;
    }

    if (keystates.up)
    {
        player->z += ELEVATION_SPEED * delta_time;
    } 
    else if (keystates.down)
    {
        player->z -= ELEVATION_SPEED * delta_time;
    }
}


void K_HandleRealtimeKeys(SDL_Scancode key_scancode, enum KBD_KEY_STATE state)
{
    if (key_scancode == keymap.forward)
        keystates.forward = state;
    else if (key_scancode == keymap.backward)
        keystates.backward = state;

    if (key_scancode == keymap.left)
        keystates.left = state;
    else if (key_scancode == keymap.right)
        keystates.right = state;

    if (key_scancode == keymap.strafe_left)
        keystates.s_left = state;
    else if (key_scancode == keymap.strafe_right)
        keystates.s_right = state;

    if (key_scancode == keymap.up)
        keystates.up = state;
    else if (key_scancode == keymap.down)
        keystates.down = state;

    if (key_scancode == keymap.toggle_map && state == true)
        keystates.map_state = !keystates.map_state;
}