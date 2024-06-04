#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
// #define INT_MAX 2147483647

// u d l r
int axisX[4] = {-1, 1, 0, 0};
int axisY[4] = {0, 0, -1, 1};
int map[100][100] = {0,};
int n, m;

struct str{
    int x;
    int y;
    int cnt;
};

void bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, 1));
    map[x][y] = 0;

    while(!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int cnt = get<2>(q.front());
        if (xx == n-1 && yy == m-1) {
            cout << cnt << endl;
            break;
        }
        q.pop();
        cnt++;

        for (int i=0; i<4; i++) {
            int tmpX = xx + axisX[i];
            int tmpY = yy + axisY[i];

            if (tmpX < 0 || tmpX >= n  || tmpY < 0 || tmpY >= m) {
                continue;
            }
            if (map[tmpX][tmpY] == 1) {
                map[tmpX][tmpY] = 0;
                q.push(make_tuple(tmpX, tmpY, cnt));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(0, 0);
    return 0;
}
