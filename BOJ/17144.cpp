#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Axis {
    int x;
    int y;
};

Axis air;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int DIR_MAX = 4;

void topCycle(vector<vector<int>>& map) {
    int x = air.x;
    int y = air.y;

    // 좌변
    for (int i=x+1; i>0; i--) {
        map[i][0] = map[i-1][0];
    }
    // 상변
    for (int i=0; i<=m-1-1; i++) {
        map[0][i] = map[0][i+1];
    }
    // 우변
    for (int i=0; i<=x-1; i++) {
        map[i][m-1] = map[i+1][m-1];
    }
    // 하변
    for (int i=m-1; i>=2; i--) {
        map[x][i] = map[x][i-1];
    }
    map[x][1] = 0;
    map[x][y] = -1;
}

void bottomCycle(vector<vector<int>>& map) {
    int x = air.x + 1;
    int y = air.y;

    // 좌
    for (int i=x+1; i<=n-2; i++) {
        map[i][0] = map[i+1][0];
    }
    // 하
    for (int i=0; i<=m-2; i++) {
        map[n-1][i] = map[n-1][i+1];
    }
    // 우
    for (int i=n-1; i>x; i--) {
        map[i][m-1] = map[i-1][m-1];
    }
    // 상
    for (int i=m-1; i>1; i--) {
        map[x][i] = map[x][i-1];
    }
    map[x][1] = 0;
    map[x][y] = -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> n >> m >> t;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
            if (v[i][j] == -1) {
                air.x = i-1;
                air.y = j;
            }
        }
    }

    while (t--) {
        vector<vector<int>> newV(n, vector<int>(m, 0));
        vector<Axis> munji;
        vector<Axis> newMunji;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] > 0) {
                    munji.push_back({i, j});
                }
            }
        }

        for (int i=0; i<munji.size(); i++) {
            int x = munji[i].x;
            int y = munji[i].y;
            int value = v[x][y];
            if (value == 0) continue;
            int spread = floor(value/5);
            for(int j=0; j<DIR_MAX; j++) {
                int mx = x + dx[j];
                int my = y + dy[j];
                if (mx < 0 || my < 0 || mx >= n || my >= m ||
                    ((mx == air.x || mx == air.x+1) && my == air.y))
                    continue;
                if (!visited[mx][my]) newMunji.push_back({mx, my});
                newV[mx][my] += spread;
                value-=spread;
                visited[mx][my] = true;
            }
            if (!visited[x][y]) newMunji.push_back({x, y});
            newV[x][y] += value;
            visited[x][y] = true;
        }

        topCycle(newV);
        bottomCycle(newV);


        munji = newMunji;
        v = newV;
    }
 
    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] > 0) {
                sum+=v[i][j];
            }
        }
    }
    cout << sum << '\n';

    return 0;
}