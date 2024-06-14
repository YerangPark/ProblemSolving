#include <iostream>
#include <queue>
#include <algorithm> // for sort()
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
int map[100][100];

void bfs(int x, int y, bool visit[100][100], int orig);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int max = 0, min = 2147483647;
    int maxCnt = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
            max = (map[i][j] > max) ? map[i][j] : max;
            min = (map[i][j] < min) ? map[i][j] : min;
        }
    }
    if (max == min) {
        if (min != 0) min--;
        else max++;
    }

    for (int m=min; m<max; m++) {
        bool visit[100][100] = {false};
        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (map[i][j] > m && !visit[i][j]) {
                    bfs(i, j, visit, m);
                    cnt++;
                }
            }
        }
        maxCnt = (maxCnt < cnt) ? cnt : maxCnt;
    }
    cout << maxCnt << endl;
}

void bfs(int x, int y, bool visit[100][100], int orig) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int mx = xx + dx[i];
            int my = yy + dy[i];
            if (mx < 0 || mx >= n || my < 0 || my >= n || visit[mx][my]) continue;
            if (map[mx][my] > orig) {
                q.push(make_pair(mx, my));
                visit[mx][my] = true;
            }
        }
    }
}

