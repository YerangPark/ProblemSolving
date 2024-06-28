#include <iostream>
#include <queue>
//#include <vector>
//#include <memory.h>
//#include <algorithm>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

struct Axis {
    int x;
    int y;
    int cnt;
    int kCnt;
};

int n, m, k;
bool map[1001][1001] = {0};
bool visited[11][1001][1001] = {false};
queue<Axis> q;

int main() {
    //    ios::sync_with_stdio(false);
    //    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            scanf("%1d", &tmp);
            map[i][j] = tmp;
        }
    }

    q.push(Axis {0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        Axis now = q.front();
        q.pop();

        if (now.x == n - 1 && now.y == m - 1) {
            cout << now.cnt << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int mx = now.x + dx[i];
            int my = now.y + dy[i];

            if (mx < 0 || mx >= n || my < 0 || my >= m) continue;

            // 벽을 부수는 경우
            if (map[mx][my] == 1 && now.kCnt < k) {
                if (!visited[now.kCnt + 1][mx][my]) {
                    q.push(Axis {mx, my, now.cnt + 1, now.kCnt + 1});
                    visited[now.kCnt + 1][mx][my] = true;
                }
            }
            // 벽이 아닌 경우
            else if (map[mx][my] == 0 && !visited[now.kCnt][mx][my]) {
                q.push(Axis {mx, my, now.cnt + 1, now.kCnt});
                visited[now.kCnt][mx][my] = true;
            }
        }
    }

    cout << -1 << "\n"; // 경로를 찾지 못한 경우 -1 출력
    return 0;
}
