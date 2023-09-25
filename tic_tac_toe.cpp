#include <iostream>
#include <vector>

using namespace std;

int sum(int a, int b, int c) {
    return a + b + c;
}
//Displaying the tic tac toe board
void printBoard(const vector<int>& xState, const vector<int>& zState) {
    cout << (xState[0] ? 'X' : (zState[0] ? 'O' : '0')) << " | "
         << (xState[1] ? 'X' : (zState[1] ? 'O' : '1')) << " | "
         << (xState[2] ? 'X' : (zState[2] ? 'O' : '2')) << endl;
    cout << "--|---|---" << endl;
    cout << (xState[3] ? 'X' : (zState[3] ? 'O' : '3')) << " | "
         << (xState[4] ? 'X' : (zState[4] ? 'O' : '4')) << " | "
         << (xState[5] ? 'X' : (zState[5] ? 'O' : '5')) << endl;
    cout << "--|---|---" << endl;
    cout << (xState[6] ? 'X' : (zState[6] ? 'O' : '6')) << " | "
         << (xState[7] ? 'X' : (zState[7] ? 'O' : '7')) << " | "
         << (xState[8] ? 'X' : (zState[8] ? 'O' : '8')) << endl;
}
//Check if either X wins or O.
int checkwin(const vector<int>& xState, const vector<int>& zState) {
    vector<vector<int>> xwins = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (const vector<int>& win : xwins) {
        if (sum(xState[win[0]], xState[win[1]], xState[win[2]]) == 3) {
            cout << "X won the match" << endl;
            return 1;
        }
        if (sum(zState[win[0]], zState[win[1]], zState[win[2]]) == 3) {
            cout << "O won the match" << endl;
            return 0;
        }
    }

    // Check for a draw
    bool isDraw = true;
    for (int i = 0; i < 9; ++i) {
        if (xState[i] == 0 && zState[i] == 0) {
            isDraw = false;
            break;
        }
    }

    if (isDraw) {
        cout << "It's a draw!" << endl;
        return 2;
    }

    return -1;
}

int main() {
    char ch;
    do{
    vector<int> xState(9, 0);
    vector<int> zState(9, 0);
    int turn = 1; // 1 for X and 0 for O.
    
    cout << "Welcome to Tic Tac Toe" << endl;
    
    while (true) {
        printBoard(xState, zState);

        if (turn == 1) {
            cout << "X's chance" << endl;
        } else {
            cout << "O's chance" << endl;
        }

        int value;
        cin >> value;

        if (value < 0 || value > 8 || (xState[value] == 1) || (zState[value] == 1)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (turn == 1) {
            xState[value] = 1;
        } else {
            zState[value] = 1;
        }

        int cwin = checkwin(xState, zState);

        if (cwin != -1) {
            cout << "Match over" << endl;
            break;
        }

        turn = 1 - turn;
    }
    printf("Do you want to play another tic tac toe game....Enter Y\n");
    scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');

    return 0;
}
