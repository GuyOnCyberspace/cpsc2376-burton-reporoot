#include <iostream>
#include "game.h"

int main() {
    Game game;
    int column;

    while (game.status() == Game::ONGOING) {
        std::cout << game;
        std::cout << "Enter column (0-6): ";
        std::cin >> column;
        if (!game.play(column)) {
            std::cout << "Invalid move! Try again.\n";
        }
    }

    std::cout << "Game Over!\n";
    Game::Status result = game.status();
    if (result == Game::PLAYER_1_WINS) std::cout << "Player 1 Wins!\n";
    else if (result == Game::PLAYER_2_WINS) std::cout << "Player 2 Wins!\n";
    else std::cout << "It's a Draw!\n";

    return 0;
}
