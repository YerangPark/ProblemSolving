#include <iostream>
#include <string>
using namespace std;
#define SIZE 6

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
    }
    else {
        n -= 1;
        int i = 1;
        while (n > 6 * i) {
            n -= 6 * i;
            i++;
        }
        cout << i + 1 << '\n';
    }
    return 0;
}