#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int t, m, n, k;
bool map[50][50] = {0};

void bfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i=0; i<t; i++) {
        int cnt = 0;
        cin >> m >> n >> k;
        for (int j=0; j<k; j++) {
            int cabX, cabY;
            cin >> cabY >> cabX;
            map[cabX][cabY] = true;
        }

        for (int a=0; a<n; a++) {
            for (int b=0; b<m; b++) {
                if (map[a][b]) {
                    bfs(a, b);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}

void bfs(int x, int y) {
    cout << "start from " << x << ", " << y << endl;
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx < 0 || my < 0 || mx >= n || my >= m || !map[mx][my]) continue;
            cout << "check " << mx << ", " << my << endl;
            q.push(make_pair(mx, my));
            map[mx][my] = false;
        }
    }
}