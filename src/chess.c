#include <stdlib.h>
#include <raylib.h>

#define CHESS_PIECE 64

typedef enum PieceType
{
    None,
    Knight,
    Rook,
    Queen,
    King,
    Pawn,
    Bishop

} PieceInfo;

typedef struct Square
{

    PieceInfo piece;
    Color color;
    int width;
    int height;
    char *containerName;
    Rectangle rect;

} Container;

typedef struct Grid
{
    int width;
    int height;
    Container containers[8][8];

} Board;

void InitializeBoardColors(Board *board)
{

    int boardWidth = board->width;
    int boardHeight = board->height;

    for (int x = 0; x < boardWidth; x++)
    {
        for (int y = 0; y < boardHeight; y++)
        {
            if ((x + y) % 2 == 0)
            {

                board->containers[x][y].color = WHITE;
            }
            else
            {
                board->containers[x][y].color = GRAY;
            }
        }
    }
}

void BoardUpdate(Board *board, int screenWidth, int screenHeight)
{

    int boardWidth = board->width;
    int boardHeight = board->height;

    for (int x = 0; x < boardWidth; x++)
    {
        for (int y = 0; y < boardHeight; y++)
        {
            board->containers[x][y].height = CHESS_PIECE;
            board->containers[x][y].width = CHESS_PIECE;

            board->containers[x][y].rect.width = CHESS_PIECE;
            board->containers[x][y].rect.height = CHESS_PIECE;
            board->containers[x][y].rect.x = screenWidth + (CHESS_PIECE * x);
            board->containers[x][y].rect.y = screenHeight + (CHESS_PIECE * y);

            DrawRectangleRec(board->containers[x][y].rect, board->containers[x][y].color);
        }
    }
}