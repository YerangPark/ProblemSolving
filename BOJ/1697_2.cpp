#include <iostream>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    queue <int> su;
    int visited[100001] = {0, };

    cin >> n >> m;
    su.push(n);

    while (!su.empty()) {
        int x = su.front();
        int time = visited[x] + 1;
        su.pop();

        if (x == m) {
            cout << time - 1 << endl;
            return 0;
        }

        if (x + 1 <= 100000 && visited[x + 1] == 0) {
            visited[x + 1] = time;
            su.push(x + 1);
        }
        if (x - 1 >= 0 && visited[x - 1] == 0) {
            visited[x - 1] = time;
            su.push(x - 1);
        }
        if (x * 2 <= 100000 && visited[x * 2] == 0) {
            visited[x * 2] = time;
            su.push(x * 2);
        }
    }
}