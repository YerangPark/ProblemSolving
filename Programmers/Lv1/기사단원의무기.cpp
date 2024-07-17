#include <string>
#include <vector>

using namespace std;

int getYaksu(int x) {
    int cnt = 0;
    if (x == 1) return 1;
    for (int i=1; i*i<=x; i++) {
        if (i * i == x) {
            cnt++;
        }
        else if (x % i == 0) {
             cnt += 2;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i=1; i<=number; i++) {
        int n = getYaksu(i);
        if (n > limit) answer += power;
        else answer += n;
    }
    return answer;
}