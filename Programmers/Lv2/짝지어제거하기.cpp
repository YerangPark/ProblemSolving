#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    vector<char> v;
    // 시간 초과를 안낼 수 있는 방법..??
    // 순회를 덜 할 수가 있나? -> 스택 자료구조로
    for (int i=0; i<s.size(); i++) {
        if (!v.empty() && s[i] == v.back()) {
            v.pop_back();
        }
        else {
            v.push_back(s[i]);
        }
    }

    return v.empty() ? 1 : 0;
}