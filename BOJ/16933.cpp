#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct Axis {
    int x;
    int y;
    int cnt;
    int kCnt;
};

int n, m, k;
bool map[1000][1000];
bool visited[2][11][1000][1000] = {false};
queue<Axis> q;

int main() {

    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int tmp;
            scanf("%1d", &tmp);
            map[i][j] = tmp;
        }
    }

    visited[0][0][0][0] = true;
    q.push(Axis {0, 0, 0, 0});
    while (!q.empty()) {
        Axis now = q.front();
        bool isDay = (now.cnt % 2 == 0) ? true : false;
        q.pop();

        if (now.x == n-1 && now.y == m-1) {
            cout << now.cnt+1 << "\n";
            return 0;
        }

        for (int i=0; i<4; i++) {
            int mx = now.x + dx[i];
            int my = now.y + dy[i];

            if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
            if (isDay && map[mx][my] && now.kCnt < k && !visited[!isDay][now.kCnt+1][mx][my]) {
                visited[!isDay][now.kCnt+1][mx][my] = true;
                q.push(Axis {mx, my, now.cnt+1, now.kCnt+1});
            }
            if (!map[mx][my] && !visited[!isDay][now.kCnt][mx][my]) {
                visited[!isDay][now.kCnt][mx][my] = true;
                q.push(Axis {mx, my, now.cnt+1, now.kCnt});
            }
        }
        if (!isDay && !visited[!isDay][now.kCnt][now.x][now.y]) {
            visited[!isDay][now.kCnt][now.x][now.y] = true;
            q.push(Axis {now.x, now.y, now.cnt+1, now.kCnt});
        }
    }
    cout << -1 << "\n";
    return 0;
}
