#include <iostream>
#include <queue>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
char map[30][30][30];

struct Axis {
    int x;
    int y;
    int z;
    int cnt;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l, r, c;
    cin >> l >> r >> c;
    while (l != 0 && r != 0 && c != 0) {
        queue<Axis> sb;
        bool success = false;
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S') sb.push(Axis {i, j, k, 0});
                }
            }
        }

        while (!sb.empty()) {
            int x = sb.front().x;
            int y = sb.front().y;
            int z = sb.front().z;
            int cnt = sb.front().cnt;
            sb.pop();

            for (int i=0; i<6; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                int mz = z + dz[i];

                if (mx < 0 || mx >= l || my < 0 || my >= r || mz < 0 || mz >= c) continue;
                if (map[mx][my][mz] == 'E') {
                    success = true;
                    cout << "Escaped in " << cnt + 1 << " minute(s)." << endl;
                    break;
                }
                if (map[mx][my][mz] != '.') continue;
                sb.push(Axis {mx, my, mz, cnt + 1});
                map[mx][my][mz] = '#';
            }
            if (success) break;
        }
        if (!success) {
            cout << "Trapped!" << endl;
        }
        cin >> l >> r >> c;
    }
}
