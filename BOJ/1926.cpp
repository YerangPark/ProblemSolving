#include <iostream>
#include <queue>
using namespace std;
// #define INT_MAX 2147483647

// u d l r
int axisX[4] = {0, 0, -1, 1};
int axisY[4] = {-1, 1, 0, 0};
int map[500][500] = {0,};
int visited[500][500] = {0,};
int n, m;

int bfs(int xx, int yy) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(yy, xx));
    visited[yy][xx] = 1;

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        cnt++;

        for (int i=0; i<4; i++) {
            int tmpX, tmpY;
            tmpX = x + axisX[i];
            tmpY = y + axisY[i];
            
            if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >=n) {
                continue;
            }
            if (!visited[tmpY][tmpX] && map[tmpY][tmpX] == 1) {
                visited[tmpY][tmpX] = 1;
                q.push(make_pair(tmpY, tmpX));
            }
        }
    }
    return cnt;
}

int main() {
    int max = 0;
    int cnt = 0;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j] && map[i][j]) {
                int tmpCnt = bfs(j, i);
                max = (max < tmpCnt) ? tmpCnt : max;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    cout << max << endl;
}
