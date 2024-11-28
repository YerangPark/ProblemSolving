#include <iostream>
#include <string>
using namespace std;

#define MAX 3

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string stringArr[3];
    for (auto& str : stringArr) {
        cin >> str;
    }

    for (int i = 0; i < MAX; i++) {
        bool isNumber = true;
        for (const auto& ch: stringArr[i]) {
            if (!(ch >= '0' && ch <= '9')) {
                isNumber = false;
                break;
            }
        }
        if (isNumber) {
            int number = stoi(stringArr[i]);
            int result = number + (3 - i);
            if (result % 3 == 0 && result % 5 == 0) {
                cout << "FizzBuzz\n";
            }
            else if (result % 3 == 0) {
                cout << "Fizz\n";
            }
            else if (result % 5 == 0) {
                cout << "Buzz\n";
            }
            else {
                cout << result << '\n';
            }
            return 0;
        }
    }
    return 0;
}