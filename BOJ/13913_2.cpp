#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

struct Subin {
    int now;
    int cnt;
};

int n, k;
bool visited[100001] = {false};
int parent[100001];
queue<Subin> q;

void recursivePrint(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(parent, -1, sizeof(parent));
    cin >> n >> k;

    visited[n] = true;
    q.push(Subin{n, 0});

    while(!q.empty()) {
        int now = q.front().now;
        int cnt = q.front().cnt;
        q.pop();
//        cout << "now : " << now << endl;

        if (now == k) {
            cout << cnt << "\n";
            recursivePrint(now);
            cout << "\n";
            break;
        }

        if (now - 1 >= 0 && !visited[now-1]) {
            visited[now-1] = true;
            q.push(Subin {now-1, cnt+1});
            parent[now-1] = now;
        }
        if (now + 1 <= 100000 && !visited[now+1]) {
            visited[now+1] = true;
            q.push(Subin {now+1, cnt+1});
            parent[now+1] = now;
        }
        if (now * 2 <= 100000 && !visited[now*2]) {
            visited[now*2] = true;
            q.push(Subin {now*2, cnt+1});
            parent[now*2] = now;
        }
    }
}

void recursivePrint(int nn) {
    if (nn != n) recursivePrint(parent[nn]);
    cout << nn << " ";
}
