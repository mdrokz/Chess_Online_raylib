#include "../headers/chess.h"

typedef enum Patterns {

    Diagonal,
    HV,
    All,
    L

} Patterns;

typedef struct Piece {

    int range;
    Patterns movePattern;
    char* displayName;
    PieceInfo piece;
    int x;
    int y;
    int index[];

} Piece;