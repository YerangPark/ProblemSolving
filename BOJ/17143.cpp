#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Shark {
    int x;
    int y;
    int speed;
    int dir;
    int size;
};
// 상 하 우 좌
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int DIR_MAX = 4;

bool cmp(Shark a, Shark b) {
    return a.size >= b.size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c, m, sum = 0;
    vector<Shark> sharks;
    cin >> r >> c >> m;
    vector<vector<int>> sea(r, vector<int>(c, 0));
    for (int i=0; i<m; i++) {
        int rr, cc, s, d, z;
        cin >> rr >> cc >> s >> d >> z;
        sharks.push_back({rr-1,cc-1,s,d-1,z});
        sea[rr-1][cc-1] = z;
    }

    sort(sharks.begin(), sharks.end(), cmp);

    for (int i=0; i<c; i++) {
        // 낚시왕이 오른쪽으로 한 칸 이동한다.
        // 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
        for (int j=0; j<r; j++) {
            if (sea[j][i] > 0) {
                sum += sea[j][i];
                sea[j][i] = -1;
                break;
            }
        }

        vector<vector<int>> newSea(r, vector<int>(c, 0));
        vector<Shark> newSharks;

        // 상어가 이동한다.
        for (int j=0; j<sharks.size(); j++) {
            Shark now = sharks[j];
            if (sea[now.x][now.y] == -1) continue;
            // 이동
            int jugi = (now.dir == 0 || now.dir == 1) ? 2 * (r - 1) : 2 * (c - 1);
            int move = now.speed % jugi;
            int x = now.x, y = now.y, d = now.dir;
            for (int s = 0; s < move; ++s) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // 벽에 닿으면 방향 반대로
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    if (d == 0) d = 1;
                    else if (d == 1) d = 0;
                    else if (d == 2) d = 3;
                    else if (d == 3) d = 2;

                    // 방향 바꾸고 다시 계산
                    nx = x + dx[d];
                    ny = y + dy[d];
                }

                x = nx;
                y = ny;
            }

            if (newSea[x][y] == 0) {
                newSharks.push_back({x, y, now.speed, d, now.size});
                newSea[x][y] = now.size;
            }
        }
        sharks = newSharks;
        sea = newSea;
    }

    cout << sum << '\n';

    return 0;
}