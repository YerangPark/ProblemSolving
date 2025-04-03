#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int SIZE = 101;
bool board[SIZE][SIZE] = {false,};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void drawDragonCurve(int x, int y, int d, int g) {
    vector<int> dirList = {d};
    for (int gen=0; gen<g; gen++) {
        vector<int> reverse;
        for (int i=dirList.size()-1; i>=0; i--) {
            reverse.push_back((dirList[i]+1)%4);
        }
        dirList.insert(dirList.end(), reverse.begin(), reverse.end());
    }
    board[y][x] = true;
    for (int dir : dirList) {
        y += dy[dir];
        x += dx[dir];
        board[y][x] = 1;
    }
}

int countSquares() {
    int cnt = 0;
    for (int i=0; i<SIZE-1; i++) {
        for (int j=0; j<SIZE-1; j++) {
            if (board[i][j] && board[i][j + 1] &&
                board[i + 1][j] && board[i + 1][j + 1]) {
                ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }

    cout << countSquares() << '\n';

    return 0;
}
