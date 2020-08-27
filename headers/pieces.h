#include "../headers/chess.h"

typedef struct Piece
{

    int range;
    Patterns movePattern;
    char *displayName;
    PieceInfo piece;
    int x;
    int y;
    int index[1];

} Piece;

typedef enum Patterns
{

    Diagonal,
    HV,
    All,
    L

} Patterns;