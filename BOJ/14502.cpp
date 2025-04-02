#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Axis {
    int x;
    int y;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int DIR_MAX = 4;

int n, m;
const int WALL_MAX = 3;
const int WALL = 1;
const int VIRUS = 2;
const int EMPTY = 0;
vector<vector<int>> v;

int bfs(queue<Axis> viruses) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;

    while(!viruses.empty()) {
        Axis now = viruses.front();
        viruses.pop();

        if (v[now.x][now.y] == EMPTY) {
            cnt++;
        }

        for (int i=0; i<DIR_MAX; i++) {
            int mx = now.x + dx[i];
            int my = now.y + dy[i];
            if (mx < 0 || mx >= n || my < 0 || my >= m ||
                visited[mx][my] || v[mx][my] != EMPTY) continue;
            visited[mx][my] = true;
            viruses.push({mx, my});
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int minVirus = 65;
    int emptyCnt = 0;
    cin >> n >> m;

    v = vector<vector<int>> (n, vector<int>(m));
    queue<Axis> viruses;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
            if (v[i][j] == VIRUS) {
                viruses.push({i, j});
            }
            else if (v[i][j] == EMPTY) {
                emptyCnt++;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] != EMPTY) continue;
            v[i][j] = WALL;

            for (int x=0; x<n; x++) {
                for (int y=0; y<m; y++) {
                    if ((i == x && j == y) || v[x][y] != EMPTY) continue;
                    v[x][y] = WALL;

                    for (int a=0; a<n; a++) {
                        for (int b=0; b<m; b++) {
                            if ((i == a && j == b) ||
                                (x == a && y == b) ||
                                v[a][b] != EMPTY) continue;
                            v[a][b] = WALL;

                            int bfsResult = bfs(viruses);
                            minVirus = min(minVirus, bfsResult);

                            v[a][b] = EMPTY;
                        }
                    }
                    v[x][y] = EMPTY;
                }
            }
            v[i][j] = EMPTY;
        }
    }
    int safe = emptyCnt - minVirus - WALL_MAX;
    cout << safe << '\n';

    return 0;
}