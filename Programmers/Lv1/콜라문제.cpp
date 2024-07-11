#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a) {
        answer += b * (n / a);
        int rest = (n % a);
        rest += b * (n / a);
        n = rest;
    }
    return answer;
}