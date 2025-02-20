#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Player { NONE = ' ', PLAYER_1 = 'X', PLAYER_2 = 'O' };

// Function Prototypes
void printRules();
void makeBoard(vector<vector<Player>> &board);
void printBoard(const vector<vector<Player>> &board);
bool play(vector<vector<Player>> &board, int col, Player currentPlayer);
GameState gameStatus(const vector<vector<Player>> &board);
bool isValidMove(const vector<vector<Player>> &board, int col);

int main() {
    char playAgain;
    do {
        vector<vector<Player>> board(ROWS, vector<Player>(COLS, Player::NONE));
        makeBoard(board);
        GameState state = GameState::ONGOING;
        Player currentPlayer = Player::PLAYER_1;
        
        while (state == GameState::ONGOING) {
            printBoard(board);
            int col;
            
            do {
                cout << "Player " << (currentPlayer == Player::PLAYER_1 ? "1 (X)" : "2 (O)") << " - Choose a column (0-6): ";
                cin >> col;
                if (cin.fail() || !isValidMove(board, col)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid move. Try again.\n";
                } else {
                    break;
                }
            } while (true);
            
            play(board, col, currentPlayer);
            state = gameStatus(board);
            currentPlayer = (currentPlayer == Player::PLAYER_1) ? Player::PLAYER_2 : Player::PLAYER_1;
        }
        
        printBoard(board);
        if (state == GameState::PLAYER_1_WINS) {
            cout << "Player 1 (X) wins!\n";
        } else if (state == GameState::PLAYER_2_WINS) {
            cout << "Player 2 (O) wins!\n";
        } else {
            cout << "It's a draw!\n";
        }
        
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}

void printRules() {
    cout << "Welcome to Connect Four!\n";
    cout << "Players take turns dropping their tokens (X or O) into one of seven columns.\n";
    cout << "The first player to connect four in a row (horizontally, vertically, or diagonally) wins!\n";
    cout << "If the board is full and no player has connected four, it's a draw.\n";
}

void makeBoard(vector<vector<Player>> &board) {
    printRules();
}

void printBoard(const vector<vector<Player>> &board) {
    cout << "\n";
    for (const auto &row : board) {
        for (const auto &cell : row) {
            cout << "| " << static_cast<char>(cell) << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    cout << "  0   1   2   3   4   5   6  \n";
}

bool play(vector<vector<Player>> &board, int col, Player currentPlayer) {
    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == Player::NONE) {
            board[row][col] = currentPlayer;
            return true;
        }
    }
    return false;
}

bool isValidMove(const vector<vector<Player>> &board, int col) {
    return col >= 0 && col < COLS && board[0][col] == Player::NONE;
}

GameState gameStatus(const vector<vector<Player>> &board) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            Player token = board[row][col];
            if (token == Player::NONE) continue;
            
            if (col + 3 < COLS && token == board[row][col+1] && token == board[row][col+2] && token == board[row][col+3])
                return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            
            if (row + 3 < ROWS && token == board[row+1][col] && token == board[row+2][col] && token == board[row+3][col])
                return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            
            if (row + 3 < ROWS && col + 3 < COLS && token == board[row+1][col+1] && token == board[row+2][col+2] && token == board[row+3][col+3])
                return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            
            if (row + 3 < ROWS && col - 3 >= 0 && token == board[row+1][col-1] && token == board[row+2][col-2] && token == board[row+3][col-3])
                return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
        }
    }
    
    for (int col = 0; col < COLS; ++col) {
        if (board[0][col] == Player::NONE)
            return GameState::ONGOING;
    }
    
    return GameState::DRAW;
}


