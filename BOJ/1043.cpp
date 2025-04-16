#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, maxGura = 0;
vector<vector<int>> party;
enum LISTEN {
    NONE,
    REAL,
    GURA
};

void dfs(int partyNum, vector<int> person, int guraCnt) {
    // 종료 조건
    if (partyNum == M) {
        maxGura = max(maxGura, guraCnt);
        return;
    }

    int guraPerson = 0;
    int realPerson = 0;
    bool canGura = true;
    for (int i=0; i<party[partyNum].size(); i++) {
        if (person[party[partyNum][i]] == REAL) {
            realPerson++;
        }
        else if (person[party[partyNum][i]] == GURA) {
            guraPerson++;
        }
    }
    if (guraPerson && realPerson) {
        // 구라친 사람과 안친 사람 섞이면 불가능한 케이스
        return;
    }
    if (!realPerson) {
        // 구라치기
        for (int i=0; i<party[partyNum].size(); i++) {
            person[party[partyNum][i]] = GURA;
        }
        dfs(partyNum+1, person, guraCnt + 1);
    }
    if (!guraPerson) {
        // 구라 못침
        // 구라 안치기
        for (int i=0; i<party[partyNum].size(); i++) {
            person[party[partyNum][i]] = REAL;
        }
        dfs(partyNum+1, person, guraCnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    vector<int> person(N+1, NONE);
    for (int i=0; i<K; i++) {
        int idx;
        cin >> idx;
        person[idx] = REAL;
    }


    party = vector<vector<int>> (M, vector<int>(0));
    for (int i=0; i<M; i++) {
        int cnt;
        cin >> cnt;
        for (int j=0; j<cnt; j++) {
            int p;
            cin >> p;
            party[i].push_back(p);
        }
    }
    dfs(0, person, 0);
    cout << maxGura << '\n';

    return 0;
}
