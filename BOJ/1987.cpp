#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int R, C;
int board[21][21] = {};
bool alphabet[26] = {false,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int DFS(int x, int y, int cnt) {
    int maxCnt = cnt;
    for (int i=0; i<4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (mx < 0 || my < 0 || mx >= R || my >= C) continue;
        if (alphabet[board[mx][my]]) continue;
        alphabet[board[mx][my]] = true;
        maxCnt = max(maxCnt, DFS(mx, my, cnt+1));
        alphabet[board[mx][my]] = false;
    }
    return maxCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; i++) {
        string str;
        cin >> str;
        for (int j=0; j<C; j++) {
            board[i][j] = (int) str[j] - 'A';
        }
    }
    alphabet[board[0][0]] = true;
    cout << DFS(0, 0, 1);

    return 0;
}
