#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define EMPTY 0
#define APPLE -1

// 우 하 좌 상
int axisX[4] = {0, 1, 0, -1}; // 행
int axisY[4] = {1, 0, -1, 0}; // 열

int n, k, l;
int board[101][101] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = APPLE;
    }

    map<int, char> m;
    cin >> l; // 방향 변환 횟수
    for (int i=0; i<l; i++) {
        int sec;
        char dir; // L : 왼쪽으로 90도 / D : 오른쪽으로 90도
        cin >> sec >> dir;
        m[sec] = dir;
    }

    int sec = 1;
    int x = 0, y = 0;
    int length = 1;
    board[0][0] = 1;
    int dir = 0;

    while(true) {
        board[x][y] = sec;
        int dx = x + axisX[dir];
        int dy = y + axisY[dir];

        if (board[dx][dy] == APPLE) {
            length++;
        }
        else if (board[dx][dy] >= sec - length + 1 ||
            dx < 0 || dy < 0 || dx >= n || dy >= n) { // SNAKE
            cout << sec << '\n';
            break;
        }

        x = dx;
        y = dy;

        if (m[sec] == 'L') {
            dir = (dir - 1 < 0) ? 3 : dir - 1;
        }
        else if (m[sec] == 'D') {
            dir = (dir + 1 > 3) ? 0 : dir + 1;
        }
        sec++;
    }
}

