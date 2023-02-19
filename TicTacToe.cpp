#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';
void draw_board() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}
bool mark_board(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    board[row][col] = player;
    return true;
}
bool check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}
void switch_player() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}
int main() {
    int choice;
    while (!check_win()) {
        draw_board();
        cout << "Player " << player << ", please enter your move: ";
        cin >> choice;
        if (mark_board(choice)) {
            switch_player();
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
    draw_board();
    cout << "Congratulations, you win! " << endl;
    return 0;
}