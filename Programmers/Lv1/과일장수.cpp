#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int t = score.size();
    sort(score.begin(), score.end());
    while(t >= m) {
        int last;
        for (int i=0; i<m; i++) {
            last = score.back();
            score.pop_back();
        }
        answer += (m * last);
        t -= m;
    }
    return answer;
}