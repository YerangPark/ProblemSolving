#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n, c, b;
    long long cCnt = 0, bCnt = 0;

    cin >> n;
    vector<long long> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    cin >> c >> b;

    for (int i=0; i<n; i++) {
        cCnt++;
        v[i] -= c;
        if (v[i] > 0) {
            bCnt += v[i] / b;
            if (v[i] % b > 0) {
                bCnt++;
            }
        }
    }
    cout << cCnt + bCnt << '\n';

    return 0;
}