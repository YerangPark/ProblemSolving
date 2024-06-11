#include <iostream>
#include <queue>
//#include <algorithm> // for sort()
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Axis {
    int x;
    int y;
    int cnt = 0;
};

//int bfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        int w, h;
        queue <Axis> sg;
        queue <Axis> fire;
        char map[1000][1000];
        bool visitSg[1000][1000] = {false,};
        bool visitFire[1000][1000] = {false,};
        bool end = false;

        // input
        cin >> w >> h;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    sg.push(Axis {i, j, 0});
                    visitSg[i][j] = true;
                }
                else if (map[i][j] == '*') {
                    fire.push(Axis {i, j, 0});
                    visitFire[i][j] = true;
                }
            }
        }

        for (int t=0; !sg.empty(); t++) {
            while (!sg.empty() && sg.front().cnt == t) {
                // sg move
                int x, y, cnt;
                x = sg.front().x;
                y = sg.front().y;
                cnt = sg.front().cnt;
                sg.pop();
                if (map[x][y] == '*') continue;
//                cout << "[" << t << "] sg move from x : " << x << " / y : " << y << endl;

                for (int i=0; i<4; i++) {
                    int mx = x + dx[i];
                    int my = y + dy[i];
                    if (mx < 0 || my < 0 || mx >= h || my >= w) {
                        cout << cnt + 1 << endl;
                        end = true;
                        break;
                    }
                    if (map[mx][my] != '.' || visitSg[mx][my]) continue;
//                    cout << "push mx : " << mx << " my : " << my << endl;
                    sg.push(Axis {mx, my, cnt+1});
                    map[mx][my] = '@';
                    visitSg[mx][my] = true;
                }
                if (end) break;
            }
            if (end) break;
            while (!fire.empty() && fire.front().cnt == t) {
                // fire move
                int x, y, cnt;
                x = fire.front().x;
                y = fire.front().y;
                cnt = fire.front().cnt;
                fire.pop();

                for (int i=0; i<4; i++) {
                    int mx = x + dx[i];
                    int my = y + dy[i];
                    if (mx < 0 || my < 0 || mx >= h || my >= w || map[mx][my] == '#' || visitFire[mx][my]) continue;
                    fire.push(Axis {mx, my, cnt+1});
                    map[mx][my] = '*';
                    visitFire[mx][my] = true;
                }
            }
        }
        if (!end) cout << "IMPOSSIBLE" << endl;
    }
}
