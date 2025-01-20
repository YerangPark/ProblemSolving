#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    queue<int> q;
    for (int i=1; i<=n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        // 젤 윗 카드 버림
        q.pop();
        // 젤 윗 카드 맨 아래로 옮김
        int front = q.front();
        q.pop();
        q.push(front);
    }
    cout << q.front() << '\n';
    // 근데 더 빨리 풀 수 있는 방법이 있지 않을까?

    return 0;
}
