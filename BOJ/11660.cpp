#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int x;
    int y;
};
int N, M;
vector<vector<int>> board;
vector<vector<int>> boardSum;
vector<Node> from;
vector<Node> to;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    board = vector<vector<int>> (N, vector<int>(N));
    boardSum = vector<vector<int>> (N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        from.push_back({x1-1, y1-1});
        to.push_back({x2-1, y2-1});
    }

    // 누적합 시키기
    // 0행, 0열
    boardSum[0][0] = board[0][0];
    for (int i=1; i<N; i++) {
        boardSum[0][i] = board[0][i] + boardSum[0][i-1];
        boardSum[i][0] = board[i][0] + boardSum[i-1][0];
    }
    for (int i=1; i<N; i++) {
        for (int j=1; j<N; j++) {
            boardSum[i][j] = boardSum[i-1][j] + boardSum[i][j-1] -
                boardSum[i-1][j-1] + board[i][j];
        }
    }

    for (int i=0; i<M; i++) {
        int ans = boardSum[to[i].x][to[i].y];
        if (from[i].x == 0 && from[i].y != 0) {
            ans -= boardSum[to[i].x][from[i].y-1];
        }
        else if (from[i].x != 0 && from[i].y == 0) {
            ans -= boardSum[from[i].x-1][to[i].y];
        }
        else if (from[i].x !=0 && from[i].y != 0){
            ans -= boardSum[to[i].x][from[i].y-1];
            ans -= boardSum[from[i].x-1][to[i].y];
            ans += boardSum[from[i].x-1][from[i].y-1];
        }
        cout << ans << '\n';
    }

    return 0;
}
