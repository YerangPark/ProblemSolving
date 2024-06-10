#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool map[101][101] = {false};
int m, n, k;

struct Axis {
    int x;
    int y;
    int cnt = 0;
};

int bfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    cin >> m >> n >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                map[j][i] = true;
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (!map[i][j]) {
                v.push_back(bfs(i,j));
            }
        }
    }

    // 정렬 후 출력
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int bfs(int x, int y) {
    int cnt = 1;
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    map[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx < 0 || my < 0 || mx >= m || my >= n || map[mx][my]) continue;
            q.push(make_pair(mx, my));
            map[mx][my] = true;
            cnt++;
        }
    }
    return cnt;
}
