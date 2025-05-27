#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];

    vector<int> dpLIS(N, 1);
    vector<int> dpLDS(N, 1);

    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (A[j] < A[i]) {
                dpLIS[i] = max(dpLIS[i], dpLIS[j] + 1);
            }
        }
    }

    for (int i=N-1; i>=0; i--) {
        for (int j=N-1; j>i; j--) {
            if (A[j] < A[i]) {
                dpLDS[i] = max(dpLDS[i], dpLDS[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i=0; i<N; i++) {
        answer = max(answer, dpLIS[i] + dpLDS[i] - 1);
    }

    cout << answer << '\n';
    return 0;
}
