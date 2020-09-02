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
    int x;
    int down;
    int y;
    int index[1];

} Piece;