#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str, boom;
    cin >> str >> boom;

    string result = "";
    int boomLen = boom.length();

    for (char ch : str) {
        result += ch;
        if (result.length() >= boomLen) {
            if (result.substr(result.length() - boomLen) == boom) {
                result.erase(result.end() - boomLen, result.end());
            }
        }
    }

    cout << (result.empty() ? "FRULA" : result) << '\n';
    return 0;
}