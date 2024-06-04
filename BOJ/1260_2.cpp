#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 점 개수, 간선 개수, 탐색 시작할 정점 번호
int n, m, v;
bool arr[1001][1001] = {false,};
bool visitDfs[1001] = {0,};

void dfs(int a) {
    cout << a << " ";
    visitDfs[a] = 1;
    for (int i=1; i<=1000; i++) {
        if (!visitDfs[i] && arr[a][i]) {
            visitDfs[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int a) {
    queue <int> q;
    int visit[1001] = {0,};
    visit[a] = 1;
    q.push(a);
    cout << q.front() << " ";
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i=1; i<=1000; i++) {
            if (!visit[i] && arr[now][i] == 1) {
                visit[i] = 1;
                q.push(i);
                cout << q.back() << " ";
            }
        }
    }
    cout << endl;
}


int main() {
    cin >> n >> m >> v;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = true;
        arr[y][x] = true;
    }

    dfs(v);
    cout << endl;
    bfs(v);
}
