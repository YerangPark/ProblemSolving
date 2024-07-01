#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class fibo {
private:
    vector<string> dp;
    int n;
public:
    fibo() {
        cin >> n;
        dp.resize(3);
        dp[0] = "0";
        dp[1] = "1";
    }

    string sum(string a, string b) {
        int num;
        int carry = 0; // 올림할 수
        string result;

        // 1의 자리부터 덧셈해야 하므로 뒤집기
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // 자릿수 맞춰주기
        while (a.length() < b.length()) {
            a += '0';
        }
        while (a.length() > b.length()) {
            b += '0';
        }

        // 일의 자리부터 차례로 더하기.
        for (int i = 0; i < a.length(); i++) {
            num = (a[i] - '0' + b[i] - '0' + carry) % 10; // 아스키 코드로 계산하기 위함.
            carry = (a[i] - '0' + b[i] - '0' + carry) / 10; // 계산된 carry는 다음 자리수(num) 덧셈할 때 쓰임.
            result += to_string(num);
        }

        // 모든 자리수 계산했는데 올림 수 남으면 최상위 자리에 덧붙임.
        if (carry != 0) {
            result += to_string(carry);
        }

        reverse(result.begin(), result.end());

        return result;
    }

    void DP() {
        if (n < 2) {
            cout << dp[n] << "\n";
        }
        for (int i = 2; i <= n; i++) {
            dp[2] = sum(dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        cout << dp[2] << "\n";
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fibo fi;
    fi.DP();
    return 0;
}
