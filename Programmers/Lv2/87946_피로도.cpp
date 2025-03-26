#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int maxCnt = 0;
void recursive(int p, int cnt, vector<bool> visited, vector<vector<int>>& dungeons);

int solution(int k, vector<vector<int>> dungeons) {
    // 던전 : 최소 필요 피로도, 소모 피로도
    // 하루에 한 번
    // 최대한 많이 탐험
    // 모든 경우의 수 체크하면서 가능한지 검사하기
    
    // 재귀로 풀면 되겠다
    vector<bool> visited(dungeons.size(), false);
    recursive(k, 0, visited, dungeons);
    return maxCnt;
}

void recursive(int p, int cnt, vector<bool> visited, vector<vector<int>>& dungeons) {
    int idx = 0;
    for (const auto& dungeon : dungeons) {
        int minP = dungeon[0];
        int conP = dungeon[1];
        if (p >= minP && p >= conP) {
            if (!visited[idx]) { // 안들린 경우
                visited[idx] = true;
                recursive(p-conP, cnt+1, visited, dungeons);
                visited[idx] = false;
            }
        }
        idx++;
    }
    maxCnt = max(maxCnt, cnt);
}