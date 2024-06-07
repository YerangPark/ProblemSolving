#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 상 하 좌 우
int axisX[4] = {-1, 1, 0, 0};
int axisY[4] = {0, 0, -1, 1};
char map[1000][1000] = {};

int main() {
    int r, c;
    cin >> r >> c;
    queue <tuple<int, int, int>> jihoon;
    queue <tuple<int, int, int>> fire;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'J') jihoon.push(make_tuple(i, j, 0));
            if (map[i][j] == 'F') fire.push(make_tuple(i, j, 0));
        }
    }

    int cnt = 0;
    while (!jihoon.empty()) {
        while (!jihoon.empty() && get<2>(jihoon.front()) == cnt) {
            int jx = get<0>(jihoon.front());
            int jy = get<1>(jihoon.front());
            jihoon.pop();
            if (map[jx][jy] == 'F') continue;
            for (int i=0; i<4; i++) {
                int mx = jx + axisX[i];
                int my = jy + axisY[i];
                if (map[mx][my] == '#') continue;
                if (mx < 0 || my < 0 || mx >= r || my >= c) {
                    cout << cnt + 1 << endl;
                    return 0;
                }
                if (map[mx][my] == '.') {
                    jihoon.push(make_tuple(mx, my, cnt + 1));
                    map[mx][my] = 'J';
                }
            }
        }

        while (!fire.empty() && get<2>(fire.front()) == cnt) {
            int fx = get<0>(fire.front());
            int fy = get<1>(fire.front());
            fire.pop();
            for (int i=0; i<4; i++) {
                int mx = fx + axisX[i];
                int my = fy + axisY[i];
                if (mx < 0 || my < 0 || mx >= r || my >= c) {
                    continue;
                }
                if (map[mx][my] == '.' || map[mx][my] == 'J') {
                    fire.push(make_tuple(mx, my, cnt + 1));
                    map[mx][my] = 'F';
                }
            }
        }
        cnt++;

//         for (int i=0; i<r; i++) {
//             for (int j=0; j<c; j++) {
//                 cout << map[i][j];
//             }
//             cout << endl;
//         }
    }
    cout << "IMPOSSIBLE" << endl;
}

