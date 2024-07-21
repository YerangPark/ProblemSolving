#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool isSosoo(int x) {
    for (int i=2; i<=sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    vector<bool> v(n+1, true);
    
    for (int i=2; i<=n; i++) {
        if (!v[i]) continue;
        if (isSosoo(i)) {
            for (int j=1; j*i <=n; j++) {
                v[i*j] = false;
            }
            answer++;
        }
    }

    return answer;
}