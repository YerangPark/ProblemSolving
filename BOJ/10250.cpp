#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // 층수, 호수, 몇 번째
    int re;
    cin >> re;
    while (re--) {
        int h, w, n;

        cin >> h >> w >> n;
        int floor = n % h == 0 ? h : n % h;
        int ho = ((n - 1) / h) + 1;

        printf("%d%02d\n", floor, ho);
    }

    return 0;
}
