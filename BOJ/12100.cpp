#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, maxBlockSize = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    array<array<int, 21>, 21> orig = {0,};
    queue<pair<array<array<int, 21>, 21>, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> orig[i][j];
        }
    }
    q.push({orig, 0});

    while (!q.empty()) {
        // cout << "------------cnt : " << q.front().second + 1 << " -------------\n";
        array<array<int, 21>, 21> map = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 5번 이동 완료 시 아웃
        if (cnt == 5) {
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    maxBlockSize = max(maxBlockSize, map[i][j]);
            continue;
        }

        // 상
        array<array<int, 21>, 21> upMap = {0,};
        for (int i=0; i<n; i++) {
            // 행
            bool isCollapsed[21] = {0,};
            int lastIdx = 0;
            for (int j=0; j<n; j++) {
                // 열
                if (map[j][i] == 0) continue;
                // 하나의 열에서 한 칸씩 내려가면서 값이 있는지 체크
                upMap[lastIdx][i] = map[j][i];
                if (lastIdx != 0 && !isCollapsed[lastIdx-1] &&
                    upMap[lastIdx][i] == upMap[lastIdx-1][i]) {
                    // 바로 위에 있는 애가 첫 요소가 아니고, 결합 안된 애면 같은 값인지 체크해서 결합
                    upMap[lastIdx-1][i] *= 2;
                    upMap[lastIdx][i] = 0;
                    isCollapsed[lastIdx-1] = true;
                    continue;
                }
                lastIdx++;
            }
        }
        q.push({upMap, cnt + 1});
        // cout << "상\n";
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << upMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // 하
        array<array<int, 21>, 21> downMap = {0,};
        for (int i=0; i<n; i++) {
            // 행
            bool isCollapsed[21] = {0,};
            int lastIdx = n - 1;
            for (int j=n; j>=0; j--) {
                // 열
                if (map[j][i] == 0) continue;
                downMap[lastIdx][i] = map[j][i];
                if (lastIdx < n && !isCollapsed[lastIdx+1] &&
                    downMap[lastIdx][i] == downMap[lastIdx+1][i]) {
                    downMap[lastIdx+1][i] *= 2;
                    downMap[lastIdx][i] = 0;
                    isCollapsed[lastIdx+1] = true;
                    continue;
                }
                lastIdx--;
            }
        }
        q.push({downMap, cnt + 1});
        // cout << "하\n";
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << downMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // 좌
        array<array<int, 21>, 21> leftMap = {0,};
        for (int i=0; i<n; i++) {
            // 열
            bool isCollapsed[21] = {0,};
            int lastIdx = 0;
            for (int j=0; j<n; j++) {
                // 행
                if (map[i][j] == 0) continue;
                leftMap[i][lastIdx] = map[i][j];
                if (lastIdx != 0 && !isCollapsed[lastIdx-1] &&
                    leftMap[i][lastIdx] == leftMap[i][lastIdx-1]) {
                    leftMap[i][lastIdx-1] *= 2;
                    leftMap[i][lastIdx] = 0;
                    isCollapsed[lastIdx-1] = true;
                    continue;
                }
                lastIdx++;
            }
        }
        q.push({leftMap, cnt + 1});
        // cout << "좌\n";
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << leftMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // 우
        array<array<int, 21>, 21> rightMap = {0,};
        for (int i=0; i<n; i++) {
            // 열
            bool isCollapsed[21] = {0,};
            int lastIdx = n - 1;
            for (int j=n; j>=0; j--) {
                // 행
                if (map[i][j] == 0) continue;
                rightMap[i][lastIdx] = map[i][j];
                if (lastIdx < n && !isCollapsed[lastIdx+1] &&
                    rightMap[i][lastIdx] == rightMap[i][lastIdx+1]) {
                    rightMap[i][lastIdx+1] *= 2;
                    rightMap[i][lastIdx] = 0;
                    isCollapsed[lastIdx+1] = true;
                    continue;
                }
                lastIdx--;
            }
        }
        q.push({rightMap, cnt + 1});
        // cout << "우\n";
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << rightMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    cout << maxBlockSize << '\n';
    return 0;
}