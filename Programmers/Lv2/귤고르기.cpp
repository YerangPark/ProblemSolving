#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int kind = 0;
    int s = tangerine.size();
    map<int, int> m;

    for (int i=0; i<s; i++) {
        if (m.find(tangerine[i]) == m.end()) { // map에 등록되지 않았으면
            kind++; // 종류 1개 늘려주기
            m[tangerine[i]] = 1;
        }
        else {
            m[tangerine[i]]++;
        }
    }

    vector<pair<int,int>> vec( m.begin(), m.end() );
    sort(vec.begin(), vec.end(), cmp);

    for (auto tan : vec) {
		// cout << "key: "<< tan.first << " | value: " << tan.second << "\n";
        s -= tan.second;
        if (s < k) {
            answer = kind;
        }
        else {
            kind--;
        }
	  }

    return answer;
}