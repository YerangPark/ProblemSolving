#include <iostream>
#include <queue>
#include <algorithm> // for max()
using namespace std;

// 상 하 좌 우
int axisX[4] = {-1, 1, 0, 0};
int axisY[4] = {0, 0, -1, 1};

// 가로 칸 수, 세로 칸 수
int m, n;
int box[1000][1000] = {0, };
int rawTomatoCnt = 0;

int main() {
    queue <tuple<int, int, int>> q;
    int max = 0;
    int rawTomatoCnt = 0;

    cin >> m >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) q.push(make_tuple(i, j, 0));
            if (box[i][j] == 0) rawTomatoCnt++;
        }
    }

    while (!q.empty()) {
        int x, y, cnt;
        x = get<0>(q.front());
        y = get<1>(q.front());
        cnt = get<2>(q.front());
        q.pop();

        for (int i=0; i<4; i++) {
            int xx, yy;
            xx = x + axisX[i];
            yy = y + axisY[i];

            if (xx < 0 || xx >=n || yy < 0 || yy >=m) continue;
            if (box[xx][yy] == 0) {
                rawTomatoCnt--;
                box[xx][yy] = 2;
                if (cnt > max) {
                    max = cnt;
                }
                q.push(make_tuple(xx, yy, cnt + 1));
            }
        }
    }
    if (rawTomatoCnt > 0) cout << -1;
    else if (max == 0) cout << 0;
    else cout << max + 1;

    // while (beforeRawTomatoCnt != rawTomatoCnt) {
    //      cout << "day " << dayCnt << endl;
    //     beforeRawTomatoCnt = rawTomatoCnt;
    //     for (int i=0; i<n; i++) {
    //         for (int j=0; j<m; j++) {
    //             if (box[i][j] == 1) {
    //                 box[i][j] = 2;
    //                 r
    //             }
    //         }
    //     }
    //     dayCnt++;
    //     for (int i=0; i<n; i++) {
    //         for (int j=0; j<m; j++) {
    //             cout << box[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // if (rawTomatoCnt == 0) cout << dayCnt - 1 << endl;
    // else cout << -1 << endl;
}
