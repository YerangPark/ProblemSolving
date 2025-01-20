#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        vector<char> v;
        string str;
        bool isString = true;

        getline(cin, str);
        if (str.length() == 1 && str[0] == '.') {
            break;
        }
        for (int i=0; i<str.length(); i++) {
            if (str[i] == '[' || str[i] == '(') {
                v.push_back(str[i]);
            }
            else if (str[i] == ']') {
                if (v.size() == 0) {
                    isString = false;
                    break;
                }
                else if (v.back() == '[') {
                    v.pop_back();
                }
                else {
                    isString = false;
                    break;
                }
            }
            else if (str[i] == ')') {
                if (v.size() == 0) {
                    isString = false;
                    break;
                }
                else if (v.back() == '(') {
                    v.pop_back();
                }
                else {
                    isString = false;
                    break;
                }
            }
        }
        if (!isString || v.size() > 0) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}
