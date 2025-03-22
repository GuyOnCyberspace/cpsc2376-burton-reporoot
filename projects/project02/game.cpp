#include "game.h"

Game::Game() : board(6, std::vector<Cell>(7, EMPTY)), currentPlayer(PLAYER_1) {}

bool Game::play(int column) {
    if (column < 0 || column >= 7) return false;
    for (int row = 5; row >= 0; --row) {
        if (board[row][column] == EMPTY) {
            board[row][column] = currentPlayer;
            currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            return true;
        }
    }
    return false;
}

Game::Status Game::status() const {
    if (checkWin(PLAYER_1)) return PLAYER_1_WINS;
    if (checkWin(PLAYER_2)) return PLAYER_2_WINS;
    if (isBoardFull()) return DRAW;
    return ONGOING;
}

void Game::display() const {
    for (const auto& row : board) {
        for (Cell cell : row) {
            char symbol = (cell == PLAYER_1) ? 'X' : (cell == PLAYER_2) ? 'O' : '.';
            std::cout << symbol << " ";
        }
        std::cout << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    game.display();
    return os;
}

bool Game::checkWin(Cell player) const {
    for (int r = 0; r < 6; ++r) {
        for (int c = 0; c < 7; ++c) {
            if (c + 3 < 7 && checkDirection(r, c, 0, 1, player)) return true;
            if (r + 3 < 6 && checkDirection(r, c, 1, 0, player)) return true;
            if (r + 3 < 6 && c + 3 < 7 && checkDirection(r, c, 1, 1, player)) return true;
            if (r - 3 >= 0 && c + 3 < 7 && checkDirection(r, c, -1, 1, player)) return true;
        }
    }
    return false;
}

bool Game::checkDirection(int r, int c, int dr, int dc, Cell player) const {
    for (int i = 0; i < 4; ++i) {
        if (board[r + i * dr][c + i * dc] != player) return false;
    }
    return true;
}

bool Game::isBoardFull() const {
    for (int c = 0; c < 7; ++c) {
        if (board[0][c] == EMPTY) return false;
    }
    return true;
}
