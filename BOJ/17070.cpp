#include <iostream>
#include <queue>
using namespace std;

int N, cnt = 0;
bool board[16][16];

enum DIR {
    HOR,
    VER,
    DIAG
};

enum MAP {
    EMPTY,
    WALL
};

struct Pipe {
    int x;
    int y;
    int dir;
};

bool checkEnd(Pipe p) {
    if (p.dir == HOR && p.x == N-1 && p.y == N-2) return true;
    else if (p.dir == VER && p.x == N-2 && p.y == N-1) return true;
    else if (p.dir == DIAG && p.x == N-2 && p.y == N-2) return true;
    return false;
}


void bfs() {
    queue<Pipe> q;
    q.push({0, 0, HOR});

    while (!q.empty()) {
        Pipe now = q.front();
        q.pop();
        if (checkEnd(now)) {
            cnt++;
            continue;
        }

        if (now.dir == HOR) { // 가로
            // 가로 이동
            if (now.y+2 < N && board[now.x][now.y+2] == EMPTY) {
                q.push({now.x, now.y+1, HOR});
            }
            // 대각 이동
            if (now.y+2 < N && now.x+1 < N &&
                board[now.x][now.y+2] == EMPTY && board[now.x+1][now.y+1] == EMPTY &&
                board[now.x+1][now.y+2] == EMPTY) {
                q.push({now.x, now.y+1, DIAG});
            }
        }
        else if (now.dir == VER) { // 세로
            // 세로 이동
            if (now.x+2 < N && board[now.x+2][now.y] == EMPTY) {
                q.push({now.x+1, now.y, VER});
            }
            // 대각 이동
            if (now.x+2 < N && now.y+1 < N &&
                board[now.x+2][now.y] == EMPTY && board[now.x+1][now.y+1] == EMPTY &&
                board[now.x+2][now.y+1] == EMPTY) {
                q.push({now.x+1, now.y, DIAG});
            }
        }
        else if (now.dir == DIAG){ // 대각선
            // 가로 이동
            if (now.x+1 < N && now.y+2 < N &&
                board[now.x+1][now.y+2] == EMPTY) {
                q.push({now.x+1, now.y+1, HOR});
            }
            // 세로 이동
            if (now.x+2 < N && now.y+1 < N &&
                board[now.x+2][now.y+1] == EMPTY) {
                q.push({now.x+1, now.y+1, VER});
            }
            // 대각 이동
            if (now.x+2 < N && now.y+2 < N &&
                board[now.x+1][now.y+2] == EMPTY && board[now.x+2][now.y+1] == EMPTY &&
                board[now.x+2][now.y+2] == EMPTY) {
                q.push({now.x+1, now.y+1, DIAG});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    bfs();

    cout << cnt << '\n';

    return 0;
}
