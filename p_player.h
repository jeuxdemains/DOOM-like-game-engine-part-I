#ifndef P_PLAYER_H
#define P_PLAYER_H

#include "typedefs.h"

typedef struct _player
{
    vec2_t position;
    double z;
    double dir_angle;
} player_t;

player_t P_Init(double x, double y, double z, double angle);

#endif /* P_PLAYER_H */
