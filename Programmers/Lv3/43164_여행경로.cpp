#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

vector<string> answer;
vector<bool> visited;

bool isFinish = false;

void dfs(string now, vector<string>& route, vector<vector<string>>& tickets) {
    // cout << now << " 탐색 시작이유" << route.size() << ' ' << tickets.size() << "\n";
    if (isFinish) return;
    
    route.push_back(now);
    
    // 종료 조건
    if (route.size() == tickets.size() + 1) {
        answer = route;
        isFinish = true;
        return;
    }
    
    // 다음 노드 탐색
    for (int i=0; i<tickets.size(); i++) {
        string departure = tickets[i][0];
        string arrival = tickets[i][1];
        // cout << "    여서 " << arrival << " 까지 간대유\n";
        
        if (departure != now || visited[i]) continue;
        // cout << "   안가본데여서 " << arrival << " 로 가유\n";
        visited[i] = true;
        dfs(arrival, route, tickets);
        visited[i] = false;
    }
    route.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> route;
    visited = vector<bool>(tickets.size() + 1, false);
    
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", route, tickets);
    
    return answer;
}