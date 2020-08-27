#include <stdlib.h>
#include <memory.h>
#include <raylib.h>
#include "../headers/chess.h"
#include <stdio.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

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

    InitializeBoardColors(&board);

    Vector2 mousePosition = {0};

    bool mouseScaleReady = false;
    bool mouseScaleMode = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(BLACK);

        BoardUpdate(&board,Width,Height);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}