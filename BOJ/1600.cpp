#include <iostream>
#include <queue>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int hx[8] = {-1, -2, -2, -1, 1, 2, 2, 1,};
int hy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

#define MAX 200

struct Monkey {
    int x;
    int y;
    int cnt;
    int kCnt;
};
// K 말같이 움직일 수 있는 최대 횟수
int k, w, h;
int arr[MAX][MAX] = {0};
bool success = false;
queue<Monkey> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> w >> h;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) arr[i][j] = -1;
        }
    }

    q.push(Monkey {0, 0, 0, 1});
    while (!q.empty()) {
        Monkey now = q.front();
        q.pop();

        if (now.x == h-1 && now.y == w-1) {
            cout << now.cnt << "\n";
            success = true;
            break;
        }

        for (int i=0; i<4; i++) {
            int mx = now.x + dx[i];
            int my = now.y + dy[i];

            if (mx < 0 || mx >= h || my < 0 || my >= w || arr[mx][my] == -1) continue;
            if (arr[mx][my] != 0 && arr[mx][my] <= now.kCnt) continue;
            q.push(Monkey {mx, my, now.cnt+1, now.kCnt});
            arr[mx][my] = now.kCnt;
        }

        if (now.kCnt > k) continue;
        for (int i=0; i<8; i++) {
            int mx = now.x + hx[i];
            int my = now.y + hy[i];

            if (mx < 0 || mx >= h || my < 0 || my >= w || arr[mx][my] == -1) continue;
            if (arr[mx][my] != 0 && arr[mx][my] <= now.kCnt+1) continue;
            q.push(Monkey {mx, my, now.cnt+1, now.kCnt+1});
            arr[mx][my] = now.kCnt+1;
        }
    }
    if (!success) cout << -1 << "\n";
}
