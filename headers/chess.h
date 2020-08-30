#include <stdlib.h>
#include <raylib.h>
#include "../headers/pieces.h";


typedef struct Square
{

    Piece Piece;
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

void BoardUpdate(Board *board);

void ContainerUpdate(Container *container);

void InitializeBoard(Board *board,int screenWidth, int screenHeight);