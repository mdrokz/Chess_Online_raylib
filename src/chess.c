#include <stdlib.h>
#include <raylib.h>
#include <string.h>
#include <stdio.h>
#include "../headers/pieces.h"

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

void InitializeBoard(Board *board, int screenWidth, int screenHeight)
{

#pragma region Initialize Board
    int boardWidth = board->width;
    int boardHeight = board->height;
    int white_pieces_length = LENGTH(white_pieces);
    int black_pieces_length = LENGTH(black_pieces);

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

// load white piece textures
#pragma region Initialize white piece textures
    for (int i = 0; i < white_pieces_length - 1; i++)
    {
        board->containers[i][0].piece.texture = LoadTexture(white_pieces[i]);
        board->containers[i][7].piece.texture = LoadTexture(black_pieces[i]);
    }
    board->containers[5][0].piece.texture = LoadTexture(white_pieces[2]);
    board->containers[6][0].piece.texture = LoadTexture(white_pieces[1]);
    board->containers[7][0].piece.texture = LoadTexture(white_pieces[0]);

// load black piece textures
#pragma region Initialize black piece textures
    board->containers[5][7].piece.texture = LoadTexture(black_pieces[2]);
    board->containers[6][7].piece.texture = LoadTexture(black_pieces[1]);
    board->containers[7][7].piece.texture = LoadTexture(black_pieces[0]);
#pragma endregion

    for (int c = 0; c < 8; c++)
    {
        board->containers[c][1].piece.texture = LoadTexture(white_pieces[5]);
        board->containers[c][6].piece.texture = LoadTexture(black_pieces[5]);
    }

#pragma endregion
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
        }
    }

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