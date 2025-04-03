#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N, M;
vector<int> nums;
map<string, bool> result;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void DFS(int idx, vector<int> selected) {
    // 개수 만족 여부 체크
    if (selected.size() >= M) {
        // 결과 중복검사
        string collapsedNum = to_string(selected[0]);
        for (int i=1; i<selected.size(); i++) {
            collapsedNum+=' ';
            collapsedNum+=to_string(selected[i]);
        }
        // 중복이면 리턴!
        if (result.find(collapsedNum) != result.end()) {
            return;
        }

        result[collapsedNum] = true;

        for (int i=0; i<selected.size(); i++) {
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // 만족 안됐으면 추가
    for (int i=idx; i<nums.size(); i++) {
        selected.push_back(nums[i]);
        DFS(i, selected);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    DFS(0, vector<int>());

    return 0;
}
