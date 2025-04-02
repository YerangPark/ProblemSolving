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

int n, l;
vector<vector<int>> v;

bool bfsRow(int idx) {
    // ROW 기준
    vector<int> already(n, false);
    queue<Axis> q;
    q.push({idx, 0});

    while(!q.empty()) {
        Axis now = q.front();
        q.pop();

        int mx = now.x;
        int my = now.y + 1;
        if (my >= n) break;

        // 경사 차이가 2 이상 난다면 불가
        if (abs(v[now.x][now.y] - v[mx][my]) > 1) return false;

        // 경사 차이가 1인데, 경사로를 놓을 수 없으면 불가
        // 1. 앞으로 이동할 높이가 더 높을 때
        if (v[now.x][now.y] < v[mx][my]) {
            // 낮은쪽 길이가 l이상인지, 이미 놓여진 경사로가 없는지 체크
            int startIdx = now.y - l + 1;
            if (startIdx < 0) return false;
            for (int i=now.y; i>=startIdx; i--) {
                if (v[now.x][now.y] != v[now.x][i] || already[i]) return false;
            }

            // 경사로 추가
            for (int i=now.y; i>=startIdx; i--) {
                already[i] = true;
            }
        }

        // 2. 앞으로 이동할 높이가 더 낮을 때
        else if (v[mx][my] < v[now.x][now.y]) {
            // 이동할 곳에 경사로 놓고, l만큼 길이가 유지되는지 확인
            int endIdx = my + l - 1;
            if (endIdx >= n) return false;
            for (int i=my; i<= endIdx; i++) {
                if (v[mx][my] != v[mx][i] || already[i]) return false;
            }

            for (int i=my; i<= endIdx; i++) {
                already[i] = true;
            }
            // l만큼 유지된다면 경사로가 끝나는 위치를 push
            my = endIdx;
        }

        // 위 케이스 모두 통과 시 패스
        q.push({mx, my});
    }
    return true;
}

bool bfsCol(int idx) {
    // COL 기준
    vector<int> already(n, false);
    queue<Axis> q;
    q.push({0, idx});

    while(!q.empty()) {
        Axis now = q.front();
        q.pop();

        int mx = now.x + 1;
        int my = now.y;

        if (mx >= n) break;

        // 경사 차이가 2 이상 난다면 불가
        if (abs(v[now.x][now.y] - v[mx][my]) > 1) return false;

        // 경사 차이가 1인데, 경사로를 놓을 수 없으면 불가
        // 1. 앞으로 이동할 높이가 더 높을 때
        if (v[now.x][now.y] < v[mx][my]) {
            // 낮은쪽 길이가 l이상인지, 이미 놓여진 경사로가 없는지 체크
            int startIdx = now.x - l + 1;

            if (startIdx < 0) return false;
            for (int i=now.x; i>=startIdx; i--) {
                if (v[now.x][now.y] != v[i][now.y] || already[i]) return false;
            }

            // 경사로 추가
            for (int i=now.x; i>=startIdx; i--) {
                already[i] = true;
            }
        }

        // 2. 앞으로 이동할 높이가 더 낮을 때
        else if (v[mx][my] < v[now.x][now.y]) {
            // 이동할 곳에 경사로 놓고, l만큼 길이가 유지되는지 확인
            int endIdx = mx + l - 1;
            if (endIdx >= n) return false;
            for (int i=mx; i<= endIdx; i++) {
                if (v[mx][my] != v[i][my] || already[i]) return false;
            }

            for (int i=mx; i<= endIdx; i++) {
                already[i] = true;
            }
            // l만큼 유지된다면 경사로가 끝나는 위치를 push
            mx = endIdx;
        }

        // 위 케이스 모두 통과 시 패스
        q.push({mx, my});
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 하나의 행, 열에 대해서 높이 차이가 날 때
    // 낮은 높이 쪽 길이가 L만큼 이어진다면
    // 경사로를 놓을 수 있음.
    int cnt = 0;
    cin >> n >> l;
    v = vector<vector<int>> (n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        // 행 기준 검사
        if (bfsRow(i)) {
            cnt++;
        }

        // 열 기준 검사
        if (bfsCol(i)) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}