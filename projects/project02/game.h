#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

class Game {
public:
    enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
    enum Cell { EMPTY, PLAYER_1, PLAYER_2 };

    Game();
    bool play(int column);
    Status status() const;
    void display() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    std::vector<std::vector<Cell>> board;
    Cell currentPlayer;
    
    bool checkWin(Cell player) const;
    bool checkDirection(int r, int c, int dr, int dc, Cell player) const;
    bool isBoardFull() const;
};

#endif // GAME_H
