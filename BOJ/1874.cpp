#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> v;
    vector<char> ans;
    bool isSuccess = true;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        q.push(arr[i]);
    }

    for (int i=0; i<n; i++) {
        // 원하는 숫자가 push될 때까지 push
        cout << "top : " << q.top() << '\n';
        while (!q.empty() && arr[i] >= q.top()) {
            v.push_back(q.top());
            ans.push_back('+');
            q.pop();
        }
        if (arr[i] == v.back()) {
            ans.push_back('-');
            v.pop_back();
        }
        else {
            isSuccess = false;
        }
    }
    if (isSuccess) {
        for (auto ch: ans) cout << ch << '\n';
    }
    else {
        cout << "NO\n";
    }
    return 0;
}
