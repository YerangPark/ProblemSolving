#include <vector>
#include <iostream>
using namespace std;

bool isSosoo(int x) {
    for (int i=2; i<x; i++) {
        if (x%i == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    // 주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수
    int size = nums.size();
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (i == j) continue;
            for (int k=j+1; k<size; k++) {
                if (i == k || j == k) continue;
                int sum = nums[i] + nums[j] + nums[k];
                if (!isSosoo(sum)) continue;
                // cout << "소수 세트 : (" << nums[i] << "+" << nums[j] << "+" << nums[k] << ") = " << sum << "\n";
                answer++;
            }
        }
    }

    return answer;
}