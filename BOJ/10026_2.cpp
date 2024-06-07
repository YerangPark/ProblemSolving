#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n;

void bfs(int x, int y, char arr[100][100]);

int main() {
    int rCnt = 0, gCnt = 0, bCnt = 0, rgCnt = 0;
    char map[100][100];
    char mapRG[100][100];

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
            mapRG[i][j] = (map[i][j] == 'G') ? 'R' : map[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] != '\0') {
                if (map[i][j] == 'R') rCnt++;
                else if (map[i][j] == 'G') gCnt++;
                else if (map[i][j] == 'B') bCnt++;
                bfs(i, j, map);
            }
            // RG
            if (mapRG[i][j] != '\0') {
                if (mapRG[i][j] == 'B') continue;
                if (mapRG[i][j] == 'R') rgCnt++;
                bfs(i, j, mapRG);
            }

        }
    }
    cout << (rCnt + gCnt + bCnt) << " " << (rgCnt + bCnt) << endl;
}

void bfs(int x, int y, char arr[100][100]) {
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    char orig = arr[x][y];

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int mx = xx + dx[i];
            int my = yy + dy[i];

            if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
            if (arr[mx][my] != orig) continue;

            arr[mx][my] = '\0';
            q.push(make_pair(mx, my));
        }
    }
}
