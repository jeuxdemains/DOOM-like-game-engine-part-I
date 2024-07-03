#include "p_player.h"

player_t P_Init(double x, double y, double z, double angle)
{
    player_t player;
    player.dir_angle = angle;
    player.position.x = x;
    player.position.y = y;
    player.z = z;

    return player;
}