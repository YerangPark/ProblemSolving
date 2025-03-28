#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, m;

enum blockType {
    BLANK,
    CCTV_MAX = 5,
    WALL,
    BRIGHT
};
// CCTV 별 방향 수
int dirs[6] = {0, 4, 2, 4, 4, 1};

int checkCCTV1(int x, int y, int dir, vector<vector<int>>& map) {
    int cnt=0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(x>=0 && y>=0 && x<n && y<m) {
        if (map[x][y] == BLANK) {
            map[x][y] = BRIGHT;
            cnt++;
        }
        else if (map[x][y] == WALL) break;
        x+=dx[dir];
        y+=dy[dir];
    }
    return cnt;
}

int checkCCTV2(int x, int y, int dir, vector<vector<int>>& map) {
    int cnt = 0;
    vector<pair<int, int>> v;
    if (dir==0) { // 가로
        if (y-1 >= 0) v.push_back({x, y-1});
        if (y+1 < m) v.push_back({x, y+1});
    }
    else { // 세로
        if (x-1 >= 0) v.push_back({x-1, y});
        if (x + 1 < n) v.push_back({x+1, y});
    }
    while(!v.empty()) {
        int mx = v.back().first;
        int my = v.back().second;
        v.pop_back();
        if (map[mx][my] == WALL) continue;

        if (map[mx][my] == BLANK) {
            map[mx][my] = BRIGHT;
            cnt++;
        }
        if (x < mx) mx++;
        if (y < my) my++;
        if (x > mx) mx--;
        if (y > my) my--;

        if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
        if (map[mx][my] == WALL) continue;
        v.push_back({mx, my});
    }
    return cnt;
}

int checkCCTV3(int x, int y, int dir, vector<vector<int>>& map) {
    int cnt = 0;
    vector<pair<int, int>> v;
    if (dir==0) { // 1사분면
        if (x-1 >= 0) v.push_back({x-1, y});
        if (y + 1 < m) v.push_back({x, y+1});
    }
    else if (dir==1) { // 2사분면
        if (x+1 < n) v.push_back({x+1, y});
        if (y+1 < m) v.push_back({x, y+1});
    }
    else if (dir==2) { // 3사분면
        if (x+1 < n) v.push_back({x+1, y});
        if (y-1 >= 0) v.push_back({x, y-1});
    }
    else { // 4사분면
        if (x-1 >= 0) v.push_back({x-1, y});
        if (y-1 >= 0) v.push_back({x, y-1});
    }

    while(!v.empty()) {
        int mx = v.back().first;
        int my = v.back().second;
        v.pop_back();
        if (map[mx][my] == WALL) continue;

        if (map[mx][my] == BLANK) {
            map[mx][my] = BRIGHT;
            cnt++;
        }
        if (x < mx) mx++;
        if (y < my) my++;
        if (x > mx) mx--;
        if (y > my) my--;

        if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
        if (map[mx][my] == WALL) continue;
        v.push_back({mx, my});
    }
    return cnt;
}

int checkCCTV4(int x, int y, int dir, vector<vector<int>>& map) {
    int cnt = 0;
    vector<pair<int, int>> v;
    if (dir==0) { // 왼쪽 빼고
        if (x-1 >= 0) v.push_back({x-1, y});
        if (y+1 < m) v.push_back({x, y+1});
        if (x+1 < n) v.push_back({x+1, y});
    }
    else if (dir==1) { // 위쪽 빼고
        if (x+1 < n) v.push_back({x+1, y});
        if (y+1 < m) v.push_back({x, y+1});
        if (y-1 >= 0) v.push_back({x, y-1});
    }
    else if (dir==2) { // 오른쪽 빼고
        if (x+1 < n) v.push_back({x+1, y});
        if (y-1 >= 0) v.push_back({x, y-1});
        if (x-1 >= 0) v.push_back({x-1, y});
    }
    else { // 아래쪽 빼고
        if (x-1 >= 0) v.push_back({x-1, y});
        if (y-1 >= 0) v.push_back({x, y-1});
        if (y+1 < m) v.push_back({x, y+1});
    }

    while(!v.empty()) {
        int mx = v.back().first;
        int my = v.back().second;
        v.pop_back();
        if (map[mx][my] == WALL) continue;

        if (map[mx][my] == BLANK) {
            map[mx][my] = BRIGHT;
            cnt++;
        }
        if (x < mx) mx++;
        if (y < my) my++;
        if (x > mx) mx--;
        if (y > my) my--;

        if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
        if (map[mx][my] == WALL) continue;
        v.push_back({mx, my});
    }
    return cnt;
}

int checkCCTV5(int x, int y, vector<vector<int>>& map) {
    int cnt = 0;
    vector<pair<int, int>> v;
    if (x-1 >= 0) v.push_back({x-1, y});
    if (x+1 < n) v.push_back({x+1, y});
    if (y-1 >= 0) v.push_back({x, y-1});
    if (y+1 < m) v.push_back({x, y+1});

    while(!v.empty()) {
        int mx = v.back().first;
        int my = v.back().second;
        v.pop_back();
        if (map[mx][my] == WALL) continue;
        if (map[mx][my] == BLANK) {
            map[mx][my] = BRIGHT;
            cnt++;
        }
        if (x < mx) mx++;
        if (y < my) my++;
        if (x > mx) mx--;
        if (y > my) my--;

        if (mx < 0 || mx >= n || my < 0 || my >= m) continue;
        if (map[mx][my] == WALL) continue;
        v.push_back({mx, my});
    }
    return cnt;
}

int recursive(vector<vector<int>> map, vector<pair<int, int>>cctvs) {
    if (cctvs.size() <= 0) return 0;
    int x = cctvs.back().first;
    int y = cctvs.back().second;
    cctvs.pop_back();
    int type = map[x][y];
    int maxCnt = 0;

    for (int i=0; i<dirs[type]; i++) {
        vector<vector<int>> copiedMap = map;
        int cnt = 0;
        if (type==1) cnt += checkCCTV1(x, y, i, copiedMap);
        else if (type==2) cnt += checkCCTV2(x, y, i, copiedMap);
        else if (type==3) cnt += checkCCTV3(x, y, i, copiedMap);
        else if (type==4) cnt += checkCCTV4(x, y, i, copiedMap);
        else if (type==5) cnt += checkCCTV5(x, y, copiedMap);
        cnt += recursive(copiedMap, cctvs);
        maxCnt = max(cnt, maxCnt);
    }
    return maxCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<int>> map;
    vector<pair<int, int>> cctv;
    int blankCnt = 0;

    cin >> n >> m;

    map = vector<vector<int>>(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] > BLANK && map[i][j] <= CCTV_MAX) {
                cctv.push_back({i, j});
            }
            else if (map[i][j] == BLANK) {
                blankCnt++;
            }
        }
    }
    if (blankCnt == 0) {
        cout << 0 << '\n';
        return 0;
    }

    cout << blankCnt - recursive(map, cctv) << '\n';

    return 0;
}