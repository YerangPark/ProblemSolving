#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(string start) {
    unordered_set<string> visited;
    queue<pair<string, int>> q;

    visited.insert(start);
    q.push({start, 0});
    while (!q.empty()) {
        auto [mapStr, cnt] = q.front();
        q.pop();

        if (mapStr == "123456780") return cnt;

        int zeroIdx = mapStr.find('0');
        int x = zeroIdx / 3;
        int y = zeroIdx % 3;

        for (int dir = 0; dir < 4; dir++) {
            int mx = x + dx[dir];
            int my = y + dy[dir];

            if (mx < 0 || mx >= 3 || my < 0 || my >= 3) continue;

            int nextZeroIdx = mx * 3 + my;

            string next = mapStr;
            swap(next[zeroIdx], next[nextZeroIdx]);

            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, cnt+1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y;
    string start = "";
    for (int i = 0; i < 9; i++) {
        int num;
        cin >> num;
        start += to_string(num);
    }

    cout << bfs(start) << '\n';

    return 0;
}