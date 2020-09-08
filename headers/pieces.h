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
    int color;
    int down;
    int indX;
    int indY;

} Piece;

typedef struct Square
{

    Piece piece;
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