#include <iostream>
#include <cstring>

using namespace std;

char board[3072][6144];

void printStar(int x, int y, int n) {
    if (n == 3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*';
        board[x+1][y+1] = '*';
        board[x+2][y-2] = '*';
        board[x+2][y-1] = '*';
        board[x+2][y] = '*';
        board[x+2][y+1] = '*';
        board[x+2][y+2] = '*';
    }
    else {
        printStar(x, y, n/2);
        printStar(x + n/2, y - n/2, n/2);
        printStar(x + n/2, y + n/2, n/2);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    memset(board, ' ', sizeof(board));
    printStar(0, N-1, N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N*2 - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}