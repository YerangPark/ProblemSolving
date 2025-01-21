#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    map<int, int> numCnt;
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if (numCnt[tmp]) {
            numCnt[tmp]++;
        }
        else {
            numCnt[tmp] = 1;
        }
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        cout << (numCnt[tmp] ? numCnt[tmp] : 0) << ' ';
    }
    return 0;
}
