#include <iostream>
using namespace std;

int factorial(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << factorial(n) / (factorial(k) * factorial(n - k)) << '\n';

    return 0;
}