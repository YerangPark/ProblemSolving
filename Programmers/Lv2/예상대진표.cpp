#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int start = 1, end = n, mid = n/2;
    int lastRound = log2(n);
    if (b < a) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    for (int i = lastRound; i > 0; i--) {
        // a와 b가 mid기준으로 서로 다른 섹션에 있을 경우
        if (start == end + 1 || (a <= mid && b > mid)) {
            answer = i;
            break;
        }
        // a와 b가 mid기준으로 둘 다 왼쪽에 있을 경우
        else if (a <= mid && b <= mid) {
            end = mid;
        }
        // a와 b가 mid기준으로 둘 다 오른쪽에 있을 경우
        else if (a > mid && b > mid) {
            start = mid + 1;
        }
            mid = start + (end - start) / 2;
    }
    return answer;
}