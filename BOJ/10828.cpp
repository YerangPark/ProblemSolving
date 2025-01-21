#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> v;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        cin >> str;
        if (str == "push") {
            int tmp;
            cin >> tmp;
            cin.ignore();
            v.push_back(tmp);
        }
        else if (str == "top") {
            if (v.size() == 0) cout << -1 << '\n';
            else cout << v.back() << '\n';
        }
        else if (str == "pop") {
            if (v.size() == 0) cout << -1 << '\n';
            else {
                cout << v.back() << '\n';
                v.pop_back();
            }
        }
        else if (str == "size") {
            cout << v.size() << '\n';
        }
        else if (str == "empty") {
            cout << v.empty() << '\n';
        }

    }
    return 0;
}
