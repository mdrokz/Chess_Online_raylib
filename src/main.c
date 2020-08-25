#include <stdlib.h>
#include <memory.h>
#include <raylib.h>
#include <stdio.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main(char *args)
{

    printf("Starting Chess Online");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess_Online");

    const Width = SCREEN_WIDTH / 2;
    const Height = SCREEN_HEIGHT / 2;

    const rectWidth = 32 * 2;
    const rectHeight = 32 * 2;
    
    Rectangle rec = {Width - (rectWidth), Height - (rectHeight), rectWidth, rectHeight};

    Rectangle rec2 = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4 + 100, 200, 80};

    Vector2 mousePosition = {0};

    bool mouseScaleReady = false;
    bool mouseScaleMode = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangleRec(rec, Fade(GREEN, 0.5f));
        // DrawLine(Width,Height,Width + 20,Height + 20,RED);
        // DrawRectangleRec(rec2, Fade(GREEN, 0.5f));

        EndDrawing();
    }

    CloseWindow();

    return 0;
}