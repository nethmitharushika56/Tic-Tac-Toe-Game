#include <iostream>
using namespace std;

char grid[3][3];

void drawplayer(int player, char symbol) {
    switch (player) {
        case 1: grid[0][0] = symbol; break;
        case 2: grid[0][1] = symbol; break;
        case 3: grid[0][2] = symbol; break;
        case 4: grid[1][0] = symbol; break;
        case 5: grid[1][1] = symbol; break;
        case 6: grid[1][2] = symbol; break;
        case 7: grid[2][0] = symbol; break;
        case 8: grid[2][1] = symbol; break;
        case 9: grid[2][2] = symbol; break;
        default: cout << "Invalid move.\n"; break;
    }
}

void displayGrid() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char symbol) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol))
            return true;
    }

    // Check diagonals
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol))
        return true;

    return false;
}

int main() {
    cout << "==============================\n";
    cout << "     TIC TAC TOE GAME\n";
    cout << "==============================\n";
    cout << "Instructions:\n";
    cout << "1. This is a 2-player game (Player X and Player O).\n";
    cout << "2. The board has 9 positions numbered 1 to 9:\n\n";
    cout << "   1 | 2 | 3\n";
    cout << "  ---+---+---\n";
    cout << "   4 | 5 | 6\n";
    cout << "  ---+---+---\n";
    cout << "   7 | 8 | 9\n\n";
    cout << "==============================\n\n";

    int player1, player2;
    int moves = 0;

    // Initialize grid with 1-9
    int n = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = '0' + n++;

    displayGrid();

    while (true) {
        cout << "First player (X): Enter the number of the place you want to draw X: ";
        cin >> player1;
        drawplayer(player1, 'X');
        displayGrid();
        moves++;
        if (checkWin('X')) {
            cout << "Player X wins!\n";
            break;
        }
        if (moves == 9) {
            cout << "It's a draw!\n";
            break;
        }

        cout << "Second player (O): Enter the number of the place you want to draw O: ";
        cin >> player2;
        drawplayer(player2, 'O');
        displayGrid();
        moves++;
        if (checkWin('O')) {
            cout << "Player O wins!\n";
            break;
        }
        if (moves == 9) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
