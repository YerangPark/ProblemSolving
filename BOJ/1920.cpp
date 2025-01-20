#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n;
    map<int, bool> numMap;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        numMap[tmp] = true;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int needCheckNum;
        cin >> needCheckNum;
        if (numMap[needCheckNum]) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}
