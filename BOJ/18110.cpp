#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    double sum = 0;
    vector<int> v;
    cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int skipCount = round((double) n * 0.15);

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (int i = skipCount; i < n - skipCount; i++) {
        sum += v[i];
    }
    cout << round(sum / (n - (skipCount * 2))) << '\n';

    return 0;
}
