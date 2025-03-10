#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[501][501];

int checkTetris1(int x, int y);
int checkTetris2(int x, int y);
int checkTetris3(int x, int y);
int checkTetris4(int x, int y);
int checkTetris5(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    int maxSum = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            maxSum = max(maxSum, checkTetris1(i, j));
            maxSum = max(maxSum, checkTetris2(i, j));
            maxSum = max(maxSum, checkTetris3(i, j));
            maxSum = max(maxSum, checkTetris4(i, j));
            maxSum = max(maxSum, checkTetris5(i, j));
        }
    }
    cout << maxSum << '\n';

    return 0;
}

int checkTetris1(int x, int y) {
    int sizeX[2] = {0, 3}; // 0-base
    int sizeY[2] = {3, 0};
    int maxSum = 0;
    // 정방향
    if (x + sizeX[0] < n && y + sizeY[0] < m) {
        int sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x][y+3];
        maxSum = max(maxSum, sum);
    }
    // 회전 방향
    if (x + sizeX[1] < n && y + sizeY[1] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+3][y];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int checkTetris2(int x, int y) {
    int sizeX = 1;
    int sizeY = 1;
    int maxSum = 0;
    if (x + sizeY < n && y + sizeX < m) {
        maxSum = map[x][y] + map[x+1][y] + map[x][y+1] + map[x+1][y+1];
    }
    return maxSum;
}

int checkTetris3(int x, int y) {
    int sizeX[4] = {2, 1, 2, 1};
    int sizeY[4] = {1, 2, 1, 2};
    int maxSum = 0;
    // 정방향
    if (x + sizeX[0] < n && y + sizeY[0] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+2][y+1];
        maxSum = max(maxSum, sum);
    }
    // 대칭
    if (x + sizeX[0] < n && y + sizeY[0] < m) {
        int sum = map[x][y+1] + map[x+1][y+1] + map[x+2][y+1] + map[x+2][y];
        maxSum = max(maxSum, sum);
    }

    // 90
    if (x + sizeX[1] < n && y + sizeY[1] < m) {
        int sum = map[x+1][y] + map[x+1][y+1] + map[x+1][y+2] + map[x][y+2];
        maxSum = max(maxSum, sum);
    }
    // 대칭
    if (x + sizeX[1] < n && y + sizeY[1] < m) {
        int sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y+2];
        maxSum = max(maxSum, sum);
    }

    // 180
    if (x + sizeX[2] < n && y + sizeY[2] < m) {
        int sum = map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+2][y+1];
        maxSum = max(maxSum, sum);
    }
    // 대칭
    if (x + sizeX[2] < n && y + sizeY[2] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x][y+1];
        maxSum = max(maxSum, sum);
    }

    // 270
    if (x + sizeX[3] < n && y + sizeY[3] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+1][y+2];
        maxSum = max(maxSum, sum);
    }
    // 대칭
    if (x + sizeX[3] < n && y + sizeY[3] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x][y+1] + map[x][y+2];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int checkTetris4(int x, int y) {
    int sizeX[2] = {2, 1};
    int sizeY[2] = {1, 2};
    int maxSum = 0;
    // 정방향
    if (x + sizeX[0] < n && y + sizeY[0] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+2][y+1];
        maxSum = max(maxSum, sum);
    }
    // 대칭
    if (x + sizeX[0] < n && y + sizeY[0] < m) {
        int sum = map[x][y+1] + map[x+1][y] + map[x+1][y+1] + map[x+2][y];
        maxSum = max(maxSum, sum);
    }

    // 90
    if (x + sizeX[1] < n && y + sizeY[1] < m) {
        int sum = map[x+1][y] + map[x+1][y+1] + map[x][y+1] + map[x][y+2];
        maxSum = max(maxSum, sum);
    }
    // 대칭
    if (x + sizeX[1] < n && y + sizeY[1] < m) {
        int sum = map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+1][y+2];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int checkTetris5(int x, int y) {
    int sizeX[4] = {1, 2, 1, 2};
    int sizeY[4] = {2, 1, 2, 1};
    int maxSum = 0;
    // 정방향
    if (x + sizeX[0] < n && y + sizeY[0] < m) {
        int sum = map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x][y+2];
        maxSum = max(maxSum, sum);
    }
    // 90
    if (x + sizeX[1] < n && y + sizeY[1] < m) {
        int sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+1][y+1];
        maxSum = max(maxSum, sum);
    }
    // 180
    if (x + sizeX[2] < n && y + sizeY[2] < m) {
        int sum = map[x+1][y] + map[x][y+1] + map[x+1][y+1] + map[x+1][y+2];
        maxSum = max(maxSum, sum);
    }
    // 270
    if (x + sizeX[3] < n && y + sizeY[3] < m) {
        int sum = map[x][y+1] + map[x+1][y+1] + map[x+2][y+1] + map[x+1][y];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}