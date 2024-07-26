#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for (int i=1; i<=n; i++) {
        int sum=i;
        for (int j=i+1; j<=n; j++) {
            if (sum == n) answer++;
            else if (sum > n) break;
            sum += j;
        }
    }
    return answer;
}