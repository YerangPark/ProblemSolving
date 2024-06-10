#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dy[8] = {-2, -1, 2, 1, -2, -1, 2, 1};

struct Axis {
    int x;
    int y;
    int cnt = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, i;
    cin >> t;
    while (t-- > 0) {
        Axis nNow, nDest;
        bool visit[300][300] = {false};
        cin >> i;
        cin >> nNow.x >> nNow.y;
        cin >> nDest.x >> nDest.y;

        queue <Axis> q;
        q.push(nNow);
        visit[nNow.x][nNow.y] = true;
        while (!q.empty()) {
            Axis night = q.front();
            q.pop();
            if (night.x == nDest.x && night.y == nDest.y) {
                cout << night.cnt << endl;
                return;
            }

            for (int j=0; j<8; j++) {
                Axis mNight;
                mNight.x = night.x + dx[j];
                mNight.y = night.y + dy[j];
                mNight.cnt = night.cnt + 1;
                if (mNight.x < 0 || mNight.y< 0 || mNight.x >= i || mNight.y >= i || visit[mNight.x][mNight.y]) continue;
                visit[mNight.x][mNight.y] = true;
                q.push(mNight);
            }
        }
    }
}
