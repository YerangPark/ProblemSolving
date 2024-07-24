#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
    for (int i=0; i<A.size(); i++) {
        answer += A[i] * B[i];
    }

    return answer;
}