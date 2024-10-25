#include <iostream>
#include <string>
using namespace std;
#define SIZE 6

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, tShirtReqire[SIZE] = {0}, t, p;
    cin >> n;
    for (int i = 0; i < SIZE; i++) {
        cin >> tShirtReqire[i];
    }
    cin >> t >> p;

    int penBundle = n / p;
    int penEach = n % p;
    int tShirtBundle = 0;
    for (int i = 0; i < SIZE; i++) {
        if (tShirtReqire[i] % t == 0) {
            tShirtBundle += tShirtReqire[i] / t;
        }
        else {
            tShirtBundle += tShirtReqire[i] / t + 1;
        }
    }

    cout << tShirtBundle << '\n' << penBundle << ' ' << penEach << '\n';

    return 0;
}