#include <iostream>
using namespace std;

#define MAX 80
int t;

int main() {
    cin >> t;
    while (t--) {
        string a, b;
        char result[82] = {0};
        int lastIdx;

        cin >> a >> b;

        for (int i=0; i < MAX; i++) {
            int aIdx = ((int) a.length() - 1) - i; // 맨 뒤에서부터 하나씩 가져오기 위함
            int bIdx = ((int) b.length() - 1) - i;

            char x = 0;
            bool nextAdd = false;

            // 종료 조건
            if (aIdx < 0 && bIdx < 0) {
                break;
            }
            // 더 짧아서 한 쪽이 먼저 끝난 경우
            else if (aIdx < 0) {
                x = b[bIdx];
            }
            else if (bIdx < 0) {
                x = a[aIdx];
            }
            // 둘 다 값이 있을 때 자릿수 덧셈
            else if (a[aIdx] == '1' && b[bIdx] == '1') {
                x = '0';
                nextAdd = true;
            }
            else if ((a[aIdx] == '0' && b[bIdx] == '1') || (a[aIdx] == '1' && b[bIdx] == '0')) {
                x = '1';
            }
            else if (a[aIdx] == '0' && b[bIdx] == '0') {
                x = '0';
            }

            // 현재 자리에 이미 1이 있는 경우
            if (result[MAX-i] == '1' && x == '1') {
                x = '0';
                nextAdd = true;
            }
            else if (result[MAX-i] == '1' && x == '0') {
                x = '1';
            }

            result[MAX-i] = x;
            lastIdx = MAX-i;
            if (nextAdd) {
                result[MAX-i-1] = '1';
                lastIdx = MAX-i-1;
            }
        }
        bool first1 = false;
        for (int i = lastIdx; i <= MAX; i++) {
            if (!(i == MAX && !first1)) {
                if (result[i] == '0' && !first1) continue;
                else if (result[i] == '1' && !first1) first1 = true;
            }
            cout << result[i];
        }
        cout << "\n";
    }
}
