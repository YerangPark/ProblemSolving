#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
struct Topni {
    int leftIdx; // 9시
    int rightIdx; // 3시
};
const int TOPNI_LENGTH = 8;
const int TOPNI_COUNT = 4;
vector<vector<int>> topni(TOPNI_COUNT, vector<int>(TOPNI_LENGTH));
vector<Topni> status(TOPNI_LENGTH, {6, 2});

void rotateTopni(int idx, int rotateDir) {
    status[idx].leftIdx -= rotateDir;
    status[idx].rightIdx -= rotateDir;
    status[idx].leftIdx = (status[idx].leftIdx + TOPNI_LENGTH) % TOPNI_LENGTH;
    status[idx].rightIdx = (status[idx].rightIdx + TOPNI_LENGTH) % TOPNI_LENGTH;
}

void moveTopni(int beforeValue, int beforeRotate, int idx, int dir) {
    // 진행 방향이 우측이면 9시랑 비교해야되고
    int checkValue;
    if (dir == 1) {
        if (beforeValue == topni[idx][status[idx].leftIdx]) {
            return;
        }
    }
    // 왼쪽이면 3시랑 비교
    else if (dir == -1) {
        if (beforeValue == topni[idx][status[idx].rightIdx]) {
            return;
        }
    }
    // 회전
    int newRotate = (beforeRotate == -1) ? 1 : -1;
    const int nextIdx = idx + dir;
    if (nextIdx >= 0 && nextIdx < TOPNI_COUNT) {
        if (dir == 1) {
            moveTopni(topni[idx][status[idx].rightIdx], newRotate, idx + dir, dir);
        }
        else if (dir == -1) {
            moveTopni(topni[idx][status[idx].leftIdx], newRotate, idx + dir, dir);
        }
    }
    rotateTopni(idx, newRotate);
    return;
}

int calculateAnswer() {
    int ans = 0;
    for (int i=0; i<4; i++) {
        int idx12 = status[i].rightIdx - 2;
        idx12 = (idx12 + TOPNI_LENGTH) % TOPNI_LENGTH;
        if (topni[i][idx12] == 1) ans += pow(2, i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k;

    for (int i=0; i<TOPNI_COUNT; i++) {
        string str;
        cin >> str;
        for(int j=0; j<TOPNI_LENGTH; j++) {
            topni[i][j] = str[j] - '0';
        }
    }

    cin >> k;
    for (int i=0; i<k; i++) {
        int n, rotateDir;
        cin >> n >> rotateDir;
        n--; // for 0-base

        if (n + 1 < TOPNI_COUNT) {
            // 오른쪽 전파();
            moveTopni(topni[n][status[n].rightIdx], rotateDir, n+1, 1);
        }
        if (n - 1 >= 0) {
            // 왼쪽 전파(인덱스, 진행 방향(+1/-1), 회전 방향(+1/-1));
            moveTopni(topni[n][status[n].leftIdx], rotateDir, n-1, -1);
        }
        rotateTopni(n, rotateDir);
    }
    cout << calculateAnswer() << '\n';

    return 0;
}