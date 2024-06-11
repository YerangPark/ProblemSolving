#include <iostream>
#include <queue>
#include <algorithm> // for sort()
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool map[25][25] = {false};
int n;

int bfs(int x, int y);

int main() {
    vector <int> v;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a;
            scanf("%1d", &a);
            map[i][j] = a;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j]) {
                v.push_back(bfs(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(auto p:v) cout << p << '\n';
}

int bfs(int x, int y) {
    int cnt = 1;
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    map[x][y] = false;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int mx = xx + dx[i];
            int my = yy + dy[i];
            if (mx < 0 || my < 0 || mx >= n || my >= n || !map[mx][my]) continue;
            q.push(make_pair(mx, my));
            map[mx][my] = false;
            cnt++;
        }
    }
    return cnt;
}
