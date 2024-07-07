#include <iostream>
#include <queue>
using namespace std;

int n, k, mov = 1;
queue<int> q;
bool visited[2][500001] = {false}; // 0: 짝수초 방문여부 기록
int ans = -1;

void bfs() {
    while (!q.empty()) {
        k += mov;

        // 실패 조건: 50만 넘어가는 경우
        if (k > 500000) {
            ans = -1;
            return;
        }

        // 성공 조건: visit한 곳에 방문하는 경우
        if (visited[mov % 2][k]) {
            ans = mov;
            return;
        }

        // 순회. 같은 cnt를 갖는 경우 처리
        int siz = q.size();
        for (int i=0; i<siz; i++) {
            int x = q.front();
            q.pop();

            for (int nx : {x - 1, x + 1, x * 2}) {
                if (nx == k) {
                    ans = mov;
                    return;
                }
                if (nx < 0 || nx > 500000) continue;
                if (visited[mov % 2][nx]) continue;
                visited[mov % 2][nx] = true;
                q.push(nx);
            }
        }
        mov++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }

    q.push(n);
    bfs();

    cout << ans;
    return 0;
}
