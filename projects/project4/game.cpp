#include "game.h"
#include <iostream>

Game::Game() : currentPlayer(Player::PLAYER1), gameOver(false) {
    // Initialize the grid to NONE
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = Player::NONE;
        }
    }
}

void Game::handleEvent(SDL_Event& e) {
    if (gameOver) return;

    // Handle mouse click for placing a piece
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        int row = y / (600 / GRID_SIZE);
        int col = x / (800 / GRID_SIZE);
        
        // Place the piece if the spot is empty
        if (grid[row][col] == Player::NONE) {
            grid[row][col] = currentPlayer;
            if (checkWin()) {
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
    }

    // Handle keyboard input for replay (e.g., R for restart)
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_r) {
            reset();
        }
    }
}

void Game::update() {
    // Additional logic can be added here (e.g., AI or automatic updates)
}

void Game::draw(SDL_Renderer* renderer) {
    // Render the grid and pieces
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            SDL_Rect cell = { j * (800 / GRID_SIZE), i * (600 / GRID_SIZE), 800 / GRID_SIZE, 600 / GRID_SIZE };
            if (grid[i][j] == Player::PLAYER1) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red for Player1
            } else if (grid[i][j] == Player::PLAYER2) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue for Player2
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White for empty
            }
            SDL_RenderFillRect(renderer, &cell);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black border
            SDL_RenderDrawRect(renderer, &cell);
        }
    }

    displayResult(renderer);
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == Player::PLAYER1) ? Player::PLAYER2 : Player::PLAYER1;
}

bool Game::checkWin() {
    // Check for a win condition (horizontal, vertical, or diagonal)
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != Player::NONE)
            return true;
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != Player::NONE)
            return true;
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != Player::NONE)
        return true;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != Player::NONE)
        return true;

    return false;
}

void Game::displayResult(SDL_Renderer* renderer) {
    if (gameOver) {
        // Display winner message
        SDL_Color color = { 255, 255, 255, 255 }; // White color
        // Use SDL_ttf or custom text rendering to display "Player 1 wins" or "Player 2 wins"
    }
}

void Game::reset() {
    gameOver = false;
    currentPlayer = Player::PLAYER1;
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = Player::NONE;
        }
    }
}
