#include <iostream>
#include <string>
#include <queue>

using namespace std;

string bfs(int a, int b);

struct Data {
    int number;
    string command;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
    }
    return 0;
}

string bfs(int a, int b) {
    bool visited[10000] = {false, };
    queue<Data> q;
    q.push({a, ""});

    while (!q.empty()) {
        int now = q.front().number;
        string command = q.front().command;
        q.pop();

        if (now == b) {
            return command;
        }

        // D 연산
        int next = now * 2;
        if (next >= 10000) {
            next %= 10000;
        }
        if (!visited[next]) {
            q.push({next, command + 'D'});
            visited[next] = true;
        }

        // S 연산
        next = now - 1;
        if (next < 0) {
            next = 9999;
        }
        if (!visited[next]) {
            q.push({next, command + 'S'});
            visited[next] = true;
        }

        // L 연산
        int d1, d2, d3, d4;
        // d2 d3 d4 d1 순
        d1 = now / 1000;
        d2 = (now % 1000) / 100;
        d3 = (now % 100) / 10;
        d4 = now % 10;

        next = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
        if (!visited[next]) {
            q.push({next, command + 'L'});
            visited[next] = true;
        }

        // R 연산
        next = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
        if (!visited[next]) {
            q.push({next, command + 'R'});
            visited[next] = true;
        }
    }
    return "";
};
