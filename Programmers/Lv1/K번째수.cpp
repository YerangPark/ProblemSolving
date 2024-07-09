#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int t = commands.size();
    for (int i=0; i<t; i++) {
        int from = commands[i][0];
        int to = commands[i][1];
        int where = commands[i][2];
        
        vector<int> v;
        for(int j=from-1; j<=to-1; j++) {
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[where-1]);
    }
    return answer;
}