#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    vector<int> v;
    cin >> n >> k;
    queue<int> q;
    for (int i=1; i<=n; i++) {
        q.push(i);
    }
    while (v.size() < n) {
        for (int i=0; i<k-1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int num = q.front();
        q.pop();
        v.push_back(num);
    }

    // Print
    cout << "<";
    for (int i=0; i<n; i++) {
        cout << v[i];
        if (i != n-1) cout << ", ";
    }
    cout << ">\n";
    return 0;
}
