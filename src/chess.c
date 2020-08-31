#include <stdlib.h>
#include <raylib.h>
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

Vector2 mousePosition = {0};

static void InitializePieces(Container containers[8][8])
{
    int white_pieces_length = LENGTH(white_pieces);
    // load white piece textures
#pragma region Initialize white piece textures
    for (int i = 0; i < white_pieces_length - 1; i++)
    {
        // set texture,pieceType and position of piece inside container
        containers[i][0].piece.texture = LoadTexture(white_pieces[i]);
        containers[i][0].piece.pieceType = pieces[i];

        containers[i][0].piece.x = containers[i][0].rect.x;
        containers[i][0].piece.y = containers[i][0].rect.y;

        containers[i][7].piece.texture = LoadTexture(black_pieces[i]);
        containers[i][7].piece.pieceType = pieces[i];

        containers[i][7].piece.x = containers[i][0].rect.x;
        containers[i][7].piece.y = containers[i][0].rect.y;
    }
    containers[5][0].piece.texture = LoadTexture(white_pieces[2]);
    containers[5][0].piece.pieceType = pieces[2];

    containers[6][0].piece.texture = LoadTexture(white_pieces[1]);
    containers[6][0].piece.pieceType = pieces[1];

    containers[7][0].piece.texture = LoadTexture(white_pieces[0]);
    containers[7][0].piece.pieceType = pieces[0];

    containers[5][0].piece.x = containers[5][0].rect.x;
    containers[5][0].piece.y = containers[5][0].rect.y;

    containers[6][0].piece.x = containers[5][0].rect.x;
    containers[6][0].piece.y = containers[5][0].rect.y;

    containers[7][0].piece.x = containers[7][0].rect.x;
    containers[7][0].piece.y = containers[7][0].rect.y;

// load black piece textures
#pragma region Initialize black piece textures
    containers[5][7].piece.texture = LoadTexture(black_pieces[2]);
    containers[5][7].piece.pieceType = pieces[2];

    containers[6][7].piece.texture = LoadTexture(black_pieces[1]);
    containers[6][7].piece.pieceType = pieces[1];

    containers[7][7].piece.texture = LoadTexture(black_pieces[0]);
    containers[7][7].piece.pieceType = pieces[0];
#pragma endregion

    for (int c = 0; c < 8; c++)
    {
        containers[c][1].piece.texture = LoadTexture(white_pieces[5]);
        containers[c][1].piece.pieceType = pieces[5];

        containers[c][6].piece.texture = LoadTexture(black_pieces[5]);
        containers[c][6].piece.pieceType = pieces[5];
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
        DrawTexture(board->containers[i][0].piece.texture, board->containers[i][0].rect.x, board->containers[i][0].rect.y, WHITE);
        DrawTexture(board->containers[i][7].piece.texture, board->containers[i][7].rect.x, board->containers[i][7].rect.y, WHITE);
    }

    DrawTexture(board->containers[5][0].piece.texture, board->containers[5][0].rect.x, board->containers[5][0].rect.y, WHITE);
    DrawTexture(board->containers[6][0].piece.texture, board->containers[6][0].rect.x, board->containers[6][0].rect.y, WHITE);
    DrawTexture(board->containers[7][0].piece.texture, board->containers[7][0].rect.x, board->containers[7][0].rect.y, WHITE);

    DrawTexture(board->containers[5][7].piece.texture, board->containers[5][7].rect.x, board->containers[5][7].rect.y, WHITE);
    DrawTexture(board->containers[6][7].piece.texture, board->containers[6][7].rect.x, board->containers[6][7].rect.y, WHITE);
    DrawTexture(board->containers[7][7].piece.texture, board->containers[7][7].rect.x, board->containers[7][7].rect.y, WHITE);


    for (int c = 0; c < 8; c++)
    {
        DrawTexture(board->containers[c][1].piece.texture, board->containers[c][1].rect.x, board->containers[c][1].rect.y, WHITE);
        DrawTexture(board->containers[c][6].piece.texture, board->containers[c][6].rect.x, board->containers[c][6].rect.y, WHITE);
    }
}

static void PieceUpdate(Container *container)
{

    mousePosition = GetMousePosition();

    PieceInfo pieceType = container->piece.pieceType;

    if (IsMouseButtonDown(0))
    {
        OnPieceDown(pieceType);
    }
    else if (IsMouseButtonReleased(0))
    {
        OnPieceReleased(pieceType);
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
                PieceUpdate(&board->containers[x][y]);
            }
        }
    }

    DrawPieces(board);
}