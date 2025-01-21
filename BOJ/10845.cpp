#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    queue<int> q;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        cin >> str;
        if (str == "push") {
            int tmp;
            cin >> tmp;
            cin.ignore();
            q.push(tmp);
        }
        else if (str == "front") {
            if (q.size() == 0) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (str == "back") {
            if (q.size() == 0) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
        else if (str == "pop") {
            if (q.size() == 0) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (str == "size") {
            cout << q.size() << '\n';
        }
        else if (str == "empty") {
            cout << q.empty() << '\n';
        }

    }
    return 0;
}
