#include <stdlib.h>
#include <memory.h>
#include <raylib.h>
#include "../headers/chess.h"
#include <stdio.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600

#define CHESS_PIECE 64

int main(char *args)
{

    printf("Starting Chess Online");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess_Online");

    const Width = (SCREEN_WIDTH - (CHESS_PIECE * 8)) / 2;
    const Height = (SCREEN_HEIGHT - (CHESS_PIECE * 8)) / 2;

    Board board = {};

    board.height = 8;
    board.width = 8;

    InitializeBoard(&board,Width, Height);


    SetTargetFPS(165);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        BoardUpdate(&board);

        #ifndef DEBUG
        DrawFPS(0,0);
        #endif

        EndDrawing();
    }

    CloseWindow();

    return 0;
}