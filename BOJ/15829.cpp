#include <iostream>
#include <vector>
using namespace std;

#define R 31
#define M 1234567891

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l;
    cin >> l;
    vector <char> v;
    for (int i=0; i<l; i++) {
        char ch;
        cin >> ch;
        v.push_back(ch);
    }

    unsigned long long hash = 0;
    unsigned long long r_pow = 1;

    for (int i=0; i<l; i++) {
        int now = (int) v[i] - 'a' + 1;
        hash = (hash + (now * r_pow) % M) % M;
        r_pow = (r_pow * R) % M;
    }
    cout << hash << '\n';

    return 0;
}