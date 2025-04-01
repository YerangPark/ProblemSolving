#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct sharkMove {
    int x;
    int y;
    int time;
};
int n, sx, sy, sSize = 2, t = 0, eatCnt = 0;
vector<vector<int>> v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int DIR_MAX = 4;
bool sortQ(sharkMove a, sharkMove b) {
    if (a.x < b.x) return true;
    else if (a.x > b.x) return false;
    else {
        if (a.y < b.y) return true;
        else return false;
    }
}
bool bfsFind() {
    queue<sharkMove> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<sharkMove> ready;
    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!q.empty()) {
        sharkMove now = q.front();
        q.pop();
        if (v[now.x][now.y] > 0 && v[now.x][now.y] <= 6 &&
            v[now.x][now.y] < sSize) {
            if (ready.empty())
                ready.push_back(now);
            else if (ready[0].time == now.time) {
                ready.push_back(now);
            }
            continue;
        }

        for (int i=0; i<DIR_MAX; i++) {
            int mx = now.x + dx[i];
            int my = now.y + dy[i];

            if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
            if (visited[mx][my] || v[mx][my] > sSize) continue;

            visited[mx][my] = true;
            q.push({mx, my, now.time+1});
        }
    }
    if (!ready.empty()) {
        // readyQ 중에서 가장 위에 있으면서, 가장 왼쪽에 있는 물고기 먹음
        sort(ready.begin(), ready.end(), sortQ);
        sharkMove now = ready[0];
        v[now.x][now.y] = 0;
        sx = now.x;
        sy = now.y;
        t += now.time;
        eatCnt++;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    v = vector<vector<int>>(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 9) {
                sx = i;
                sy = j;
            }
        }
    }
    v[sx][sy] = 0;

    while (true) {
        // 상어 주변에 있는 상어보다 크기가 작은 물고기 찾기
        if (bfsFind()) {
            if (sSize == eatCnt) {
                sSize++;
                eatCnt = 0;
            }
        }
        else {
            break;
        }
        // 찾으면 해당 물고기 먹고, 상어 크기 증가, 시간 증가
        // 다 돌았는데 못찾으면 종료
    }

    cout << t << '\n';

    return 0;
}