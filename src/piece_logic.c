#include "../headers/pieces.h"
// #include <raylib.h>

// typedef enum PieceType
// {
//     None,
//     Knight,
//     Rook,
//     Queen,
//     King,
//     Pawn,
//     Bishop

// } PieceInfo;

// int originalPieceX = 0;
// int originalPieceY = 0;
// int down = 0;

void OnPieceDown(Piece *piece, Vector2 mousePosition)
{

    if (piece->down)
    {
        piece->position.x = mousePosition.x - 25;
        piece->position.y = mousePosition.y - 20;
    }

    switch (piece->pieceType)
    {
    case Rook:
    {
    }
    break;

    case Knight:
    {
    }
    break;

    case Bishop:
    {
    }
    break;

    case Queen:
    {
    }
    break;

    case King:
    {
    }
    break;

    case Pawn:
    {
    }
    break;
    }
}

void OnPieceReleased(Piece *piece, Vector2 mousePosition)
{

    if (piece->down)
    {
        piece->position.x = piece->prevPosition.x;
        piece->position.y = piece->prevPosition.y;
        piece->down = 0;
    }

    switch (piece->pieceType)
    {
    case Rook:
    {
    }
    break;

    case Knight:
    {
    }
    break;

    case Bishop:
    {
    }
    break;

    case Queen:
    {
    }
    break;

    case King:
    {
    }
    break;

    case Pawn:
    {
    }
    break;
    }
}