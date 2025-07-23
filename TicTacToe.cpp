#include <iostream>
#include <string>
#include <utility>
using namespace std;

void printBoard(char board[3][3]);
pair<int, int> getUserInput(char board[3][3]);

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int r = -1;
    int c = -1;

    for (int i = 0; i < 9; i++)
    {
        printBoard(board);
        cout << "Player is " << currentPlayer << endl;
        pair<int, int> userInput = getUserInput(board);
        r = userInput.first;
        c = userInput.second;
        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

    return 0;
}

void printBoard(char board[3][3])
{
    cout << "   |   |   " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2)
        {
            cout << "___|___|___" << endl;
        }
        cout << "   |   |   " << endl;
    }
}

pair<int, int> getUserInput(char board[3][3])
{
    int r = -1;
    int c = -1;
    while (true)
    {
        cout << "Enter r c from 0-2 for row and column: ";
        cin >> r >> c;
        if (r < 0 || r > 2 || c < 0 || c > 2)
        {
            cout << "Invalid input, try again." << endl;
        }
        else if (board[r][c] != ' ')
        {
            cout << "Tile is full, try again." << endl;
        }
        else
            break;
        r = -1;
        c = -1;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return {r, c};
}