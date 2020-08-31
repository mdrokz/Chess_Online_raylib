#include "raylib.h"

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

typedef enum Patterns
{

    Diagonal,
    HV,
    All,
    L

} Patterns;

typedef struct Piece
{

    int range;
    Patterns movePattern;
    char *displayName;
    PieceInfo pieceType;
    Texture2D texture;
    int x;
    int y;
    int index[1];

} Piece;