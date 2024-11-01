#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Tictactoe {
    vector<vector<char>> board;
    char player;

public:
    Tictactoe() : board(3, vector<char>(3, ' ')), player('X') {}

    void display() {
        cout << "Board: \n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "--+---+--\n";
        }
    }

    bool input(int rw, int cl) {
        if (rw < 0 || rw >= 3 || cl < 0 || cl >= 3 || board[rw][cl] != ' ') {
            cout << "Wrong !\n";
            return false;
        }
        board[rw][cl] = player;
        return true;
    }

    bool win() {

        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
        return false;
    }

    bool checkforusage() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') return false;
        return true;
    }

    void change() {
        player = (player == 'X') ? 'O' : 'X';
    }

    void play() {
        int rw, cl;
        while (true) {
            display();
            cout << "Player " << player << ", position  (0, 1, or 2): ";
            cin >> rw >> cl;

            if (!input(rw, cl)) continue;

            if (win()) {
                display();
                cout << "Player " << player << " wins!\n";
                break;
            }
            if (checkforusage()) {
                display();
                cout << "Draw !!\n";
                break;
            }

            change();
        }
    }
};

int main() {
    Tictactoe tictactoe;
    tictactoe.play();
    return 0;
}

 
