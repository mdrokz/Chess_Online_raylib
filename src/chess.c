#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../headers/piece_logic.h"

#define CHESS_PIECE 64

#define LENGTH(x) (sizeof(x) / sizeof((x)[0]))

static const char *white_pieces[6] = {"./assets/chess_pieces/white/piece_white_rook.png",
                                      "./assets/chess_pieces/white/piece_white_knight.png",
                                      "./assets/chess_pieces/white/piece_white_bishop.png",
                                      "./assets/chess_pieces/white/piece_white_king.png",
                                      "./assets/chess_pieces/white/piece_white_queen.png",
                                      "./assets/chess_pieces/white/piece_white_pawn.png"};

static const char *black_pieces[6] = {"./assets/chess_pieces/black/piece_black_rook.png",
                                      "./assets/chess_pieces/black/piece_black_knight.png",
                                      "./assets/chess_pieces/black/piece_black_bishop.png",
                                      "./assets/chess_pieces/black/piece_black_king.png",
                                      "./assets/chess_pieces/black/piece_black_queen.png",
                                      "./assets/chess_pieces/black/piece_black_pawn.png"};

static char *asset_path = "./assets/chess_pieces/";

static PieceInfo pieces[] = {Rook, Knight, Bishop, King, Queen, Pawn};

Vector2 mousePosition = {0};

static void InitializePieces(Container containers[8][8])
{
    int white_pieces_length = LENGTH(white_pieces);

#pragma region Initialize piece textures
    for (int i = 0; i < white_pieces_length - 1; i++)
    {
        // set texture,pieceType and position of piece inside container
        containers[i][0].piece.texture = LoadTexture(black_pieces[i]);
        containers[i][0].piece.pieceType = pieces[i];
        containers[i][0].piece.color = 0;

        containers[i][0].piece.indX = i;
        containers[i][0].piece.indY = 0;

        containers[i][7].piece.indX = i;
        containers[i][7].piece.indY = 7;

        containers[i][0].piece.position.x = containers[i][0].rect.x;
        containers[i][0].piece.position.y = containers[i][0].rect.y;

        containers[i][7].piece.texture = LoadTexture(white_pieces[i]);
        containers[i][7].piece.pieceType = pieces[i];
        containers[i][7].piece.color = 1;

        containers[i][7].piece.position.x = containers[i][7].rect.x;
        containers[i][7].piece.position.y = containers[i][7].rect.y;
    }
    int b = 2;
    for (int v = 5; v < 8; v++)
    {
        containers[v][0].piece.texture = LoadTexture(black_pieces[b]);
        containers[v][0].piece.pieceType = pieces[b];
        containers[v][0].piece.color = 0;

        containers[v][0].piece.indX = v;
        containers[v][0].piece.indY = 0;

        containers[v][0].piece.position.x = containers[v][0].rect.x;
        containers[v][0].piece.position.y = containers[v][0].rect.y;
        b--;
    }

    for (int c = 0; c < 8; c++)
    {
        containers[c][1].piece.texture = LoadTexture(black_pieces[5]);
        containers[c][1].piece.pieceType = pieces[5];
        containers[c][1].piece.color = 0;

        containers[c][1].piece.position.x = containers[c][1].rect.x;
        containers[c][1].piece.position.y = containers[c][1].rect.y;

        containers[c][1].piece.indX = c;
        containers[c][1].piece.indY = 1;

        containers[c][6].piece.texture = LoadTexture(white_pieces[5]);
        containers[c][6].piece.pieceType = pieces[5];
        containers[c][6].piece.color = 1;

        containers[c][6].piece.indX = c;
        containers[c][6].piece.indY = 6;

        containers[c][6].piece.position.x = containers[c][6].rect.x;
        containers[c][6].piece.position.y = containers[c][6].rect.y;
    }

#pragma endregion

// load white piece textures
#pragma region Initialize white piece textures

    int w = 2;
    for (int v = 5; v < 8; v++)
    {
        containers[v][7].piece.texture = LoadTexture(white_pieces[w]);
        containers[v][7].piece.pieceType = pieces[w];
        containers[v][7].piece.color = 1;

        containers[v][7].piece.indX = v;
        containers[v][7].piece.indY = 7;

        containers[v][7].piece.position.x = containers[v][7].rect.x;
        containers[v][7].piece.position.y = containers[v][7].rect.y;
        w--;
    }

#pragma endregion
}

void InitializeBoard(Board *board, int screenWidth, int screenHeight)
{

#pragma region Initialize Board
    int boardWidth = board->width;
    int boardHeight = board->height;
    for (int x = 0; x < boardWidth; x++)
    {
        for (int y = 0; y < boardHeight; y++)
        {
            if ((x + y) % 2 == 0)
            {

                board->containers[x][y].color = WHITE;
            }
            else
            {
                board->containers[x][y].color = GRAY;
            }

            board->containers[x][y].height = CHESS_PIECE;
            board->containers[x][y].width = CHESS_PIECE;

            board->containers[x][y].rect.width = CHESS_PIECE;
            board->containers[x][y].rect.height = CHESS_PIECE;

            board->containers[x][y].rect.x = screenWidth + (CHESS_PIECE * x);
            board->containers[x][y].rect.y = screenHeight + (CHESS_PIECE * y);
        }
    }
#pragma endregion

    InitializePieces(board->containers);
}

static void DrawPieces(Board *board)
{
    for (int i = 0; i < 5; i++)
    {
        DrawTextureV(board->containers[i][0].piece.texture, board->containers[i][0].piece.position, WHITE);
        DrawTextureV(board->containers[i][7].piece.texture, board->containers[i][7].piece.position, WHITE);
    }

    for (int v = 5; v < 8; v++)
    {
        DrawTextureV(board->containers[v][0].piece.texture, board->containers[v][0].piece.position, WHITE);

        DrawTextureV(board->containers[v][7].piece.texture, board->containers[v][7].piece.position, WHITE);
    }

    for (int c = 0; c < 8; c++)
    {
        DrawTextureV(board->containers[c][1].piece.texture, board->containers[c][1].piece.position, WHITE);
        DrawTextureV(board->containers[c][6].piece.texture, board->containers[c][6].piece.position, WHITE);
    }
}

static void PieceUpdate(Container *container, Container containers[8][8])
{

    mousePosition = GetMousePosition();

    Piece *piece = &container->piece;

    Rectangle rect = container->rect;

    if (IsMouseButtonPressed(0))
    {
        mousePosition.x = mousePosition.x - 5;
        if (CheckCollisionPointRec(mousePosition, rect))
        {
            piece->down = 1;
            piece->prevPosition.x = piece->position.x;
            piece->prevPosition.y = piece->position.y;
        }
    }

    if (IsMouseButtonDown(0) && piece->down)
    {
        OnPieceDown(piece, containers, mousePosition);
    }
    else if (IsMouseButtonReleased(0) && piece->down)
    {
        OnPieceReleased(piece, containers, mousePosition);
    }
}

void BoardUpdate(Board *board)
{

    int boardWidth = board->width;
    int boardHeight = board->height;

    for (int x = 0; x < boardWidth; x++)
    {
        for (int y = 0; y < boardHeight; y++)
        {
            DrawRectangleRec(board->containers[x][y].rect, board->containers[x][y].color);
            Piece piece = board->containers[x][y].piece;

            if (piece.pieceType != None)
            {
                PieceUpdate(&board->containers[x][y], board->containers);
            }
        }
    }

    DrawPieces(board);
}