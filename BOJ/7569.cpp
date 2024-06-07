#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {
    int m, n, h, rawTomatoCnt = 0, max = 0;
    int arr[100][100][100] = {0};
    queue <tuple<int, int, int, int>> q;

    cin >> m >> n >> h;
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) q.push(make_tuple(i, j, k, 0));
                if (arr[i][j][k] == 0) rawTomatoCnt++;
            }
        }
    }

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        int cnt = get<3>(q.front());
        q.pop();
        max = (max < cnt) ? cnt : max;

        for (int i=0; i<6; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            int mz = z + dz[i];
            if (mx < 0  || mx >= h || my < 0 || my >= n || mz < 0 || mz >= m) continue;
            if (arr[mx][my][mz] == 0) {
                q.push(make_tuple(mx, my, mz, cnt + 1));
                arr[mx][my][mz] = 1;
                rawTomatoCnt--;
            }
        }
    }

    if (rawTomatoCnt > 0) cout << -1 << endl;
    else cout << max << endl;
}