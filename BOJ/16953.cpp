#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

long a, b, ans = -1;

long mul2(long num) {
    return num *= 2;
}

long add1(long num) {
    return (num * 10) + 1;
}

void DFS(long num, long cnt) {
    if (num == b) {
        ans = cnt;
        return;
    }
    else if (num > b) {
        return;
    }
    DFS(mul2(num), cnt+1);
    DFS(add1(num), cnt+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    DFS(a, 1);

    cout << ans << '\n';

    return 0;
}
