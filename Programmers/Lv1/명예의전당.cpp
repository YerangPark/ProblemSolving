#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int i, int j) {
    return j < i;
}
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    int t = score.size();
    vector<int> v;
    for (int i=0; i<t; i++) {
        v.push_back(score[i]);
        sort(v.begin(), v.end(), compare);
        
        if (v.size() >= k) answer.push_back(v[k-1]);
        else answer.push_back(v.back());
    }
    return answer;
}