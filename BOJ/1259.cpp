#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int number) {
    string str = to_string(number);
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        if (isPalindrome(n)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}