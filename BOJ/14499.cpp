#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 우, 좌, 상, 하
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

#define BOTTOM_X 0
#define BOTTOM_Y 1
#define TOP_X 2
#define TOP_Y 1

// [0, 1]이 바닥, [2, 1]이 천장
int dice[4][3] = {{ 0,  0,  0},
                  {-1,  0, -1},
                  {-1,  0, -1},
                  {-1,  0, -1}};
void moveUp() {
    int tmp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = tmp;
}
void moveDown() {
    int tmp = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = tmp;
}
void moveLeft() {
    int tmp = dice[2][1];
    dice[2][1] = dice[0][2];
    dice[0][2] = dice[0][1];
    dice[0][1] = dice[0][0];
    dice[0][0] = tmp;
}
void moveRight() {
    int tmp = dice[0][0];
    dice[0][0] = dice[0][1];
    dice[0][1] = dice[0][2];
    dice[0][2] = dice[2][1];
    dice[2][1] = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, x, y, k;

    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<int> order(k);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i=0; i<k; i++) {
        cin >> order[i];
    }


    for (int i=0; i<k; i++) {
        // 맵 이동
        int mx = x + dx[order[i]-1];
        int my = y + dy[order[i]-1];

        if (mx < 0 || mx >= n || my < 0 || my >= m) continue;

        switch(order[i]) {
            case 1: moveRight(); break;
            case 2: moveLeft(); break;
            case 3: moveUp(); break;
            case 4: moveDown(); break;
        }

        if (map[mx][my] == 0) {
            map[mx][my] = dice[BOTTOM_X][BOTTOM_Y];
        }
        else if (map[mx][my] > 0) {
            dice[BOTTOM_X][BOTTOM_Y] = map[mx][my];
            map[mx][my] = 0;
        }
        cout << dice[TOP_X][TOP_Y] << '\n';
        x = mx;
        y = my;
    }
    return 0;
}