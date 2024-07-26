#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get1count(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int origCnt = get1count(n);
    for (int i=n+1; true; i++) {
        if (get1count(i) == origCnt) {
            answer = i;
            break;
        }
    }
    
    return answer;
}