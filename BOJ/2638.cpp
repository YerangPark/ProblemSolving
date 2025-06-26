#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> board;
queue<pair<int, int>> cheese;

enum {
    EMPTY,
    CHEESE
};
// 고립된 공기는 공기가 아님... 외부와 접촉한 공기에 닿은 치즈만 녹아야 함.
// 공기를 체크해야 함.
void checkAir(vector<vector<int>>& air) {
    queue<pair<int, int>> airQ;
    air = vector<vector<int>>(N, vector<int>(M, 0));
    airQ.push({0, 0});
    air[0][0] = 1;

    while (!airQ.empty()) {
        auto [x, y] = airQ.front();
        airQ.pop();
        for (int i=0; i<4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx < 0 || my < 0 || mx >= N || my >= M) continue;
            if (board[mx][my] == EMPTY && air[mx][my] == EMPTY) {
                air[mx][my] = 1;
                airQ.push({mx, my});
            }
        }
    }
}

bool meltCheese() {
    vector<vector<int>> air;
    checkAir(air);

    vector<pair<int, int>> meltedCheese;
    bool ans = true;

    int cheeseCnt = cheese.size();
    for (int i=0; i<cheeseCnt; i++) {
        auto [x, y] = cheese.front();
        cheese.pop();

        int emptyCnt = 0;
        for(int i=0; i<4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx < 0 || my < 0 || mx >= N || my >= M) continue;
            if (air[mx][my]) {
                emptyCnt++;
            }
        }
        if (emptyCnt < 2) cheese.push({x, y});
        else {
            meltedCheese.push_back({x, y});
        }
    }

    if (meltedCheese.empty()) ans = false;

    while (!meltedCheese.empty()) {
        auto [x, y] = meltedCheese.back();
        meltedCheese.pop_back();
        board[x][y] = EMPTY;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    board = vector<vector<int>>(N, vector<int>(M));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] == CHEESE) {
                cheese.push({i, j});
            }
        }
    }

    int time = 0;
    while (true) {
        if (!meltCheese()) break;
        time++;
    }

    cout << time << '\n';

    return 0;
}