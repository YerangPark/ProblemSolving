#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a+b-c << '\n';
    string tmp = to_string(a) + to_string(b);
    int tmpNum = stoi(tmp);
    cout << tmpNum - c << '\n';

    return 0;
}
