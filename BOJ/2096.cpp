#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[100000][3];
// N 최댓값만큼 만들 필요가 없구나...
// 2줄만 만들고 최근 누적값까지만 기록하고 i % 2 로 줄만 번갈아 사용하면 됨... 충격💥
int dpMax[2][3];
int dpMin[2][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }

    dpMax[0][0] = board[0][0];
    dpMax[0][1] = board[0][1];
    dpMax[0][2] = board[0][2];

    dpMin[0][0] = board[0][0];
    dpMin[0][1] = board[0][1];
    dpMin[0][2] = board[0][2];

    for (int i=1; i<N; i++) {
        int before = (i - 1) % 2;
        dpMax[i % 2][0] = board[i][0] + max(dpMax[before][0], dpMax[before][1]);
        dpMax[i % 2][1] = board[i][1] + max({dpMax[before][0], dpMax[before][1], dpMax[before][2]});
        dpMax[i % 2][2] = board[i][2] + max(dpMax[before][1], dpMax[before][2]);

        dpMin[i % 2][0] = board[i][0] + min(dpMin[before][0], dpMin[before][1]);
        dpMin[i % 2][1] = board[i][1] + min({dpMin[before][0], dpMin[before][1], dpMin[before][2]});
        dpMin[i % 2][2] = board[i][2] + min(dpMin[before][1], dpMin[before][2]);
    }

    int last = (N+1)%2;
    cout << max({dpMax[last][0], dpMax[last][1], dpMax[last][2]}) << ' ' <<
    min({dpMin[last][0], dpMin[last][1], dpMin[last][2]}) << '\n';

    return 0;
}
