#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <memory.h> // for memset() in BOJ
#include <algorithm> // for max()
using namespace std;

bool comp(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // pair
    vector<pair<int, double>> vv;
    vv.push_back(make_pair(1, 2));
    sort(vv.begin(), vv.end(), comp); // 2번째 값이 큰 순으로, 1번째 값이 작은 순으로 정렬을

    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i].first << " " << vv[i].second << "\n";
    }

    // tuple
    queue<tuple<int, int, int, int>> q;
    q.push({1, 2, 3, 4});

    return 0;
}
