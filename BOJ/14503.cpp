#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

enum floorStatus {
    DIRTY,
    WALL,
    CLEAN
};

vector<vector<int>> floorMap;
int n, m, r, c, d, maxCnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int DIR_MAX = 4;

struct Robot {
    int x;
    int y;
    int dir;
    int cnt;
};

void bfs() {
    queue<Robot> q;
    q.push({r, c, d, 0});

    while (!q.empty()) {
        Robot now = q.front();
        q.pop();

        if (floorMap[now.x][now.y] == DIRTY) {
            floorMap[now.x][now.y] = CLEAN;
            now.cnt++;
            maxCnt = max(maxCnt, now.cnt);
        }

        bool isAnyDirty = false;
        for (int i=0; i<DIR_MAX; i++) {
            int mx = now.x + dx[i];
            int my = now.y + dy[i];
            if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if (floorMap[mx][my] == DIRTY) isAnyDirty = true;
        }

        if (!isAnyDirty) {
            int mx = now.x + dx[(now.dir + 2) % 4];
            int my = now.y + dy[(now.dir + 2) % 4];
            if (mx < 0 || my < 0 || mx >= n || my >= m || floorMap[mx][my] == WALL) continue;
            q.push({mx, my, now.dir, now.cnt});
            continue;
        }

        int newDir = (now.dir - 1 + 4) % 4;

        int mx = now.x + dx[newDir];
        int my = now.y + dy[newDir];
        if (mx >= 0 && my >= 0 && mx < n && my < m) {
            if (floorMap[mx][my] == DIRTY) {
                q.push({mx, my, newDir, now.cnt});
                continue;
            }
        }
        q.push({now.x, now.y, newDir, now.cnt});

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;
    floorMap = vector<vector<int>>(n, vector<int>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> floorMap[i][j];
        }
    }
    
    bfs();
    cout << maxCnt << '\n';

    return 0;
}