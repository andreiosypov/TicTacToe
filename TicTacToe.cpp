#include <iostream>
#include <string>
using namespace std;

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

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

    return 0;
}