#include <iostream>
#include <vector>

using namespace std;

bool check_if_win(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// display board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char symbol = (board[i][j] != ' ') ? board[i][j] : '-';
            cout << symbol << " ";
        }
        cout << endl;
    }
}

bool check_if_draw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

void play_game() {
    vector<vector<char>> board(3, vector<char>(3, ' '));  
    char current_player = 'X';  

    do {
        cout << "Current Board:" << endl;
        displayBoard(board);

        int row, col;
        cout << "Player " << current_player << ", enter your move (row and column, separated by space &  between 1-3) :  ";
        cin >> row >> col;
        row--;
        col--;

        // Check if the entered position is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Move is not valid !! Please enter the values correctly !!  Try again." << endl;
            continue;
        }

        board[row][col] = current_player;

        if (check_if_win
        (board, current_player)) {
            cout << "Player " << current_player << " wins!" << endl;
            break;
        }

        if (check_if_draw(board)) {
            cout << "The game is a draw!" << endl;
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';

    } while (true);
    cout << "Final Board:" << endl;
    displayBoard(board);
}

int main() {
    char if_play_again;
    
    do {
        play_game();
        cout << "Do you want to play again? (y/n): ";
        cin >> if_play_again;

    } while (if_play_again == 'y' || if_play_again == 'Y');
    
    cout << "Thank you for playing Tic-Tac-Toe  Do play again next time !" << endl;
    return 0;
}
