#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Chicken {
    int x;
    int y;
    int dis;
};
struct House {
    int x;
    int y;
};
int N, M, ans = 100*13;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// int board[51][51];
vector<Chicken> chicken;
vector<House> houses;

int calculateChickenDistance(vector<Chicken> chicken) {
    int sum = 0;
    for (House& house : houses) {
        int minDis = 101;
        for (int k=0; k<M; k++) {
            int dis = abs(chicken[k].x - house.x) + abs(chicken[k].y - house.y);
            minDis = min(dis, minDis);
        }
        sum += minDis;
    }
    return sum;
}

void DFS(int idx, vector<Chicken> selected) {
    // M길이가 되면
    if (selected.size() >= M) {
        // 치킨거리 계산해서 min이면 갱신
        ans = min(ans, calculateChickenDistance(selected));
        return;
    }
    // M 길이가 안되면 치킨 또 추가
    for (int i=idx; i<chicken.size(); i++) {
        selected.push_back(chicken[i]);
        DFS(i+1, selected);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int tmp;
            cin >> tmp;
            // cin >> board[i][j];
            if (tmp == 1) {
                houses.push_back({i,j});
            }
            if (tmp == 2) {
                chicken.push_back({i, j, 0});
            }
        }
    }

    // 치킨집을 없앴을 때 최소거리 더 적은지 체크하기 위한 DFS
    DFS(0, vector<Chicken>());

    cout << ans << '\n';

    return 0;
}
