#include <iostream>
#include <queue>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
bool map[1000][1000];
bool visited[1000][1000] = {false};
bool visitedCrash[1000][1000] = {false};

struct Axis {
    int x;
    int y;
    int cnt;
    bool crash;
};

int main() {
    int n, m;
    queue<Axis> q;
    bool success = false;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int tmp;
            scanf("%1d", &tmp);
            map[i][j] = tmp;
        }
    }

    q.push(Axis {0, 0, 0, false});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        bool crash = q.front().crash;
        q.pop();
        if (x == n-1 && y == m-1) {
            cout << cnt + 1 << endl;
            success = true;
            break;
        }

        for (int i=0; i<4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];

            if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
            if (crash && visitedCrash[mx][my]) continue;
            else if (!crash && visited[mx][my]) continue;

            if (map[mx][my] == 1 && !crash) {
                q.push(Axis {mx, my, cnt + 1, true});
                visitedCrash[mx][my] = true;
            }
            else if (map[mx][my] == 0) {
                if (crash) visitedCrash[mx][my] = true;
                else visited[mx][my] = true;
                q.push(Axis {mx, my, cnt + 1, crash});
            }
        }
    }
    if (!success) cout << -1 << endl;
}
