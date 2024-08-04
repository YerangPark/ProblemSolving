#include <string>
#include <vector>

using namespace std;

int dp[100001] = {0};

int fibo(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (dp[n] != 0) return dp[n];
    dp[n] = (fibo(n-1) + fibo(n-2)) % 1234567;
    return dp[n];
}

int solution(int n) {
    return fibo(n);
}