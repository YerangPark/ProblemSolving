#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
//int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, cnt = 1;
    bool map[101][101] = {false};
    bool visited[101][101] = {false};
    vector<pair<int, int>> v[101][101];
    queue<pair<int, int>> q;

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a, b});
    }

    q.push({1, 1});
    visited[1][1] = true;
    map[1][1] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 켤 수 있으면 켜기
        if (!v[x][y].empty()) {
            for (int i=0; i<v[x][y].size(); i++) {
                int tmpX = v[x][y][i].first;
                int tmpY = v[x][y][i].second;
                if (map[tmpX][tmpY]) continue;
                cnt++;
                map[tmpX][tmpY] = true;
                // 켠 방 주위에 방문했던 방 있는지 체크
                bool approach = false;
                for (int i=0; i<4; i++) {
                    int mx = tmpX + dx[i];
                    int my = tmpY + dy[i];
                    if (mx < 1 || mx > n || my < 1 || my > n) continue;
                    if (visited[mx][my]) approach = true;
                }

                if (approach) {
                    q.push({tmpX, tmpY});
                    visited[tmpX][tmpY] = true;
                }
            }
        }

        // 4방 이동
        for (int i=0; i<4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];

            if (mx < 1 || mx > n || my < 1 || my > n) continue;
            if (visited[mx][my] || !map[mx][my]) continue;
            q.push({mx, my});
            visited[mx][my] = true;
        }
    }
    cout << cnt << "\n";
}
