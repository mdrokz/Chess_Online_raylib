#include <stdlib.h>
#include <raylib.h>

typedef enum PieceType
{
    Knight,
    Rook,
    Queen,
    King,
    Pawn,
    Bishop,
    None

} PieceInfo;

typedef struct Square
{

    PieceInfo Piece;
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

void BoardUpdate(Board *board, int screenWidth, int screenHeight);

void ContainerUpdate(Container *container);

void InitializeBoardColors(Board *board);