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
    Vector2 prevPosition;
    Vector2 position;
    int down;
    int index[1];

} Piece;