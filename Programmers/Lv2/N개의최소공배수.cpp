#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int max = 0;

    // 최댓값 찾기
    for (int i=0; i<arr.size(); i++) {
        max = (arr[i] > max) ? arr[i] : max;
    }

    // 최댓값 기준으로 1배, 2배, ..., n배 해가며 다른 원소들에게도 동일한 배수인지 나눠서 검사
    for (int i=1; true; i++) {
        int now = max * i;
        bool isAns = true;
        for (int j=0; j<arr.size(); j++) {
            if (now % arr[j] != 0) {
                isAns = false;
                break;
            }
        }
        if (isAns) {
            answer = now;
            break;
        }
    }
    return answer;
}