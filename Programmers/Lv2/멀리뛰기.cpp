#include <string>
#include <vector>

using namespace std;

int dp[2000] = {0};

long long jump(int now) {
    if (now == 0) return 1;
    else if (now < 0) return 0;
    else if (dp[now] != 0) return dp[now];
    dp[now] = jump(now-1) % 1234567 + jump(now-2) % 1234567;
    return dp[now] % 1234567;
}

long long solution(int n) {
    long long answer = jump(n);
    return answer;
}