#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    while (a && b && c) {
        int aa, bb, cc;
        if (a > b) {
            if (a > c) {
                aa = a;
                bb = b;
                cc = c;
            }
            else {
                aa = c;
                bb = b;
                cc = a;
            }
        }
        else {
            if (b > c) {
                aa = b;
                bb = c;
                cc = a;
            }
            else {
                aa = c;
                bb = a;
                cc = b;
            }
        }
        if (aa * aa == bb * bb + cc * cc) {
            cout << "right\n";
        }
        else {
            cout << "wrong\n";
        }

        cin >> a >> b >> c;
    }
}