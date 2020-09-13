#include "../headers/pieces.h"

void OnPieceDown(Piece *piece, Container containers[8][8], Vector2 mousePosition)
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
        int i = 0;
    }
    break;

    case Pawn:
    {
        int indX = piece->indX;
        int indY = piece->indY;

        int x1 = 0;
        int y1 = 0;

        int x2 = 0;
        int y2 = 0;

        if (piece->color == 1)
        {
            Container container = containers[indX][indY - 1];
            Container container2 = containers[indX][indY - 2];

            x1 = container.rect.x + 30;
            y1 = container.rect.y + 30;

            x2 = container2.rect.x + 30;
            y2 = container2.rect.y + 30;
        }
        else
        {
            Container container = containers[indX][indY + 1];
            Container container2 = containers[indX][indY + 2];

            x1 = container.rect.x;
            y1 = container.rect.y + 10;

            x2 = container2.rect.x;
            y2 = container2.rect.y + 10;
        }

        DrawCircle(x1, y1, 10, LIGHTGRAY);
        DrawCircle(x2, y2, 10, LIGHTGRAY);
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