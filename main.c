#include <stdio.h>

#include "p_player.h"
#include "g_game_state.h"
#include "w_window.h"
#include "r_renderer.h"
#include "k_keyboard.h"

#define SCRNW 1024
#define SCRNH 768
#define FPS 120

void GameLoop(game_state_t *game_state, player_t *player)
{
    while(game_state->is_running)
    {
        G_FrameStart();

        K_HandleEvents(game_state, player);
        R_Render(player, game_state);

        G_FrameEnd(game_state);
    }
}

int main()
{
    game_state_t game_state = G_Init(SCRNW, SCRNH, FPS);
    player_t player = P_Init(40, 40, SCRNH * 10, M_PI/2);
    K_InitKeymap();
    W_Init(SCRNW, SCRNH);
    R_Init(W_Get(), &game_state);

    sector_t s1 = R_CreateSector(10, 0, 0xd6382d, 0xf54236, 0x9c2921);
    sector_t s2 = R_CreateSector(20, 0, 0xd6382d, 0xf54236, 0x9c2921);
    sector_t s3 = R_CreateSector(30, 0, 0xd6382d, 0xf54236, 0x9c2921);
    sector_t s4 = R_CreateSector(40, 0, 0xd6382d, 0xf54236, 0x9c2921);

    sector_t s5 = R_CreateSector(80, 0, 0x29ba48, 0x43f068, 0x209138);
    sector_t s6 = R_CreateSector(80, 0, 0x29ba48, 0x43f068, 0x209138);
    sector_t s7 = R_CreateSector(80, 0, 0x29ba48, 0x43f068, 0x209138);

    sector_t s8 = R_CreateSector(80, 0, 0x29ba48, 0xd43f068, 0x209138);
    sector_t s9 = R_CreateSector(80, 0, 0x29ba48, 0xd43f068, 0x209138);
    sector_t s10 = R_CreateSector(80, 0, 0x29ba48, 0xd43f068, 0x209138);

    sector_t s11 = R_CreateSector(30, 0, 0xa3a24b, 0xd9d764, 0x858338);
    sector_t s12 = R_CreateSector(30, 0, 0xa3a24b, 0xd9d764, 0x858338);

    sector_t s13 = R_CreateSector(10, 0, 0xa3a24b, 0xd9d764, 0x858338);
    sector_t s14 = R_CreateSector(10, 0, 0xa3a24b, 0xd9d764, 0x858338);
    sector_t s15 = R_CreateSector(30, 10, 0xa3a24b, 0xd9d764, 0x858338);
    sector_t s16 = R_CreateSector(30, 10, 0xa3a24b, 0xd9d764, 0x858338);

    int s1v[4 * 4] =
        {
            70, 220, 100, 220,
            100, 220, 100, 240,
            100, 240, 70, 240,
            70, 240, 70, 220};

    int s2v[4 * 4] =
        {
            70, 200, 100, 200,
            100, 200, 100, 220,
            100, 220, 70, 220,
            70, 220, 70, 200};

    int s3v[4 * 4] =
        {
            70, 180, 100, 180,
            100, 180, 100, 200,
            100, 200, 70, 200,
            70, 200, 70, 180};

    int s4v[8 * 4] =
        {
            70, 120, 100, 120,
            100, 120, 110, 140,
            110, 140, 110, 160,
            110, 160, 100, 180,
            100, 180, 70, 180,
            70, 180, 60, 160,
            60, 160, 60, 140,
            60, 140, 70, 120};

    int s5v[4 * 4] =
        {
            30, 190, 40, 190,
            40, 190, 50, 200,
            50, 200, 50, 220,
            50, 220, 30, 190};

    int s6v[4 * 4] =
        {
            30, 120, 40, 120,
            40, 120, 40, 190,
            40, 190, 30, 190,
            30, 190, 30, 120};

    int s7v[4 * 4] =
        {
            60, 70, 60, 90,
            60, 90, 40, 120,
            40, 120, 30, 120,
            30, 120, 60, 70};

    int s8v[4 * 4] =
        {
            120, 200, 130, 190,
            130, 190, 140, 190,
            140, 190, 120, 220,
            120, 220, 120, 200};

    int s9v[4 * 4] =
        {
            130, 120, 140, 120,
            140, 120, 140, 190,
            140, 190, 130, 190,
            130, 190, 130, 120};

    int s10v[4 * 4] =
        {
            110, 70, 140, 120,
            140, 120, 130, 120,
            130, 120, 110, 90,
            110, 90, 110, 70};

    int s11v[4 * 4] =
        {
            30, 20, 50, 20,
            50, 20, 50, 50,
            50, 50, 30, 50,
            30, 50, 30, 20};

    int s12v[4 * 4] =
        {
            120, 20, 140, 20,
            140, 20, 140, 50,
            140, 50, 120, 50,
            120, 50, 120, 20};

    // --- columns
    int s13v[4 * 4] =
        {
            30, 250, 60, 250,
            60, 250, 60, 300,
            60, 300, 30, 300,
            30, 300, 30, 250};

    int s14v[4 * 4] =
        {
            110, 250, 140, 250,
            140, 250, 140, 300,
            140, 300, 110, 300,
            110, 300, 110, 250};

    int s15v[4 * 4] =
        {
            40, 260, 50, 260,
            50, 260, 50, 290,
            50, 290, 40, 290,
            40, 290, 40, 260};

    int s16v[4 * 4] =
        {
            120, 260, 130, 260,
            130, 260, 130, 290,
            130, 290, 120, 290,
            120, 290, 120, 260};

    for (int i = 0; i < 16; i += 4)
    {
        wall_t w = R_CreateWall(s1v[i], s1v[i + 1], s1v[i + 2], s1v[i + 3]);
        R_SectorAddWall(&s1, w);

        w = R_CreateWall(s2v[i], s2v[i + 1], s2v[i + 2], s2v[i + 3]);
        R_SectorAddWall(&s2, w);

        w = R_CreateWall(s3v[i], s3v[i + 1], s3v[i + 2], s3v[i + 3]);
        R_SectorAddWall(&s3, w);

        //----

        w = R_CreateWall(s5v[i], s5v[i + 1], s5v[i + 2], s5v[i + 3]);
        R_SectorAddWall(&s5, w);
        w = R_CreatePortal(s6v[i], s6v[i + 1], s6v[i + 2], s6v[i + 3], 20, 10);
        R_SectorAddWall(&s6, w);
        w = R_CreateWall(s7v[i], s7v[i + 1], s7v[i + 2], s7v[i + 3]);
        R_SectorAddWall(&s7, w);

        w = R_CreateWall(s8v[i], s8v[i + 1], s8v[i + 2], s8v[i + 3]);
        R_SectorAddWall(&s8, w);
        w = R_CreatePortal(s9v[i], s9v[i + 1], s9v[i + 2], s9v[i + 3], 20, 10);
        R_SectorAddWall(&s9, w);
        w = R_CreateWall(s10v[i], s10v[i + 1], s10v[i + 2], s10v[i + 3]);
        R_SectorAddWall(&s10, w);

        //---
        w = R_CreateWall(s11v[i], s11v[i + 1], s11v[i + 2], s11v[i + 3]);
        R_SectorAddWall(&s11, w);
        w = R_CreateWall(s12v[i], s12v[i + 1], s12v[i + 2], s12v[i + 3]);
        R_SectorAddWall(&s12, w);

        w = R_CreateWall(s13v[i], s13v[i + 1], s13v[i + 2], s13v[i + 3]);
        R_SectorAddWall(&s13, w);
        w = R_CreateWall(s14v[i], s14v[i + 1], s14v[i + 2], s14v[i + 3]);
        R_SectorAddWall(&s14, w);
        w = R_CreateWall(s15v[i], s15v[i + 1], s15v[i + 2], s15v[i + 3]);
        R_SectorAddWall(&s15, w);
        w = R_CreateWall(s16v[i], s16v[i + 1], s16v[i + 2], s16v[i + 3]);
        R_SectorAddWall(&s16, w);
    }

    for (int i = 0; i < 8 * 4; i += 4)
    {
        wall_t w = R_CreateWall(s4v[i], s4v[i + 1], s4v[i + 2], s4v[i + 3]);
        R_SectorAddWall(&s4, w);
    }

    R_AddSectorToQueue(&s1);
    R_AddSectorToQueue(&s2);
    R_AddSectorToQueue(&s3);
    R_AddSectorToQueue(&s4);
    R_AddSectorToQueue(&s5);
    R_AddSectorToQueue(&s6);
    R_AddSectorToQueue(&s7);
    R_AddSectorToQueue(&s8);
    R_AddSectorToQueue(&s9);
    R_AddSectorToQueue(&s10);
    R_AddSectorToQueue(&s11);
    R_AddSectorToQueue(&s12);
    R_AddSectorToQueue(&s13);
    R_AddSectorToQueue(&s14);
    R_AddSectorToQueue(&s15);
    R_AddSectorToQueue(&s16);

    GameLoop(&game_state, &player);

    return 0;
    }