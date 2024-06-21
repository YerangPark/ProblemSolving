#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int n, m;
int map[300][300] = {0};
deque <pair<int, int>> ice;

void melt();
int getLumpCnt();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int yearCnt = 0;
    int lump = 0;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0) ice.push_back(make_pair(i, j));
        }
    }

    while (!ice.empty()) {
        yearCnt++;
        melt();
        lump = getLumpCnt();
        if (lump >= 2) {
            cout << yearCnt << endl;
            break;
        }
    }
    if (lump < 2) {
        cout << 0 << endl;
    }

}

void melt() {
    int size = ice.size();
    queue<pair<pair<int, int>, int>> q;

    for (int i=0; i<size; i++) {
        int x = ice.front().first;
        int y = ice.front().second;
        int val = map[x][y];
        ice.pop_front();

        // 4 방향 체크하며 0 개수만큼 빼주기
        for (int j=0; j<4; j++) {
            int mx = x + dx[j];
            int my = y + dy[j];
            if (map[mx][my] == 0) val--;
        }
        val = (val < 0) ? 0 : val;
        if (val > 0) {
            ice.push_back(make_pair(x, y));
        }
        q.push(make_pair(make_pair(x, y), val));
    }

    // 녹은거 한 번에 적용
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int val = q.front().second;
        q.pop();
        map[x][y] = val;
    }
}

int getLumpCnt() {
    bool visit[300][300] = {false};
    int lumpCnt = 0;

    for (int i=0; i<ice.size(); i++) {
        int x = ice[i].first;
        int y = ice[i].second;

        if (!visit[x][y]) {
            lumpCnt++;
            queue <pair<int, int>> q;
            q.push(make_pair(x, y));
            while(!q.empty()) {
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();

                for (int j=0; j<4; j++) {
                    int mx = xx + dx[j];
                    int my = yy + dy[j];
                    if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
                    if (map[mx][my] != 0 && !visit[mx][my]) {
                        visit[mx][my] = true;
                        q.push(make_pair(mx, my));
                    }
                }
            }
        }
    }
    return lumpCnt;
}
