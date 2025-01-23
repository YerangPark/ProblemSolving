#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<int> v(k);
    for(int i=0; i<k; i++) {
        cin >> v[i];
    }
    long long left = 1, right = *max_element(v.begin(), v.end());
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = 0;

        for (int i=0; i<k; i++) {
            cnt += v[i] / mid;
        }
        if (cnt >= n) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << answer << '\n';

    return 0;
}
