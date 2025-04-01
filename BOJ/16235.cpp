#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tree {
    int x;
    int y;
    int age;
};

vector<vector<int>> field;
vector<vector<int>> fertilizer;
// 상하좌우 좌상 좌하 우상 우하
int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
const int DIR_MAX = 8;

bool sortTrees(Tree a, Tree b) {
    return a.age < b.age;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    deque<Tree> aliveTrees;
    fertilizer = vector<vector<int>>(n, vector<int>(n));
    field = vector<vector<int>>(n, vector<int>(n, 5));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> fertilizer[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        aliveTrees.push_back({x-1, y-1, z});
    }

    sort(aliveTrees.begin(), aliveTrees.end(), sortTrees);
    for (int i=0; i<k; i++) {
        deque<Tree> newAliveTrees;
        deque<Tree> babyTrees;
        vector<Tree> dieTrees;
        // 봄 : 나이만큼 양분 먹고 나이 증가
        // 어린 순으로 먹고 못/덜먹은 애들은 사망
        for (int j=0; j<aliveTrees.size(); j++) {
            Tree now = aliveTrees[j];
            if (field[now.x][now.y] >= now.age) {
                field[now.x][now.y] -= now.age;
                newAliveTrees.push_back({now.x, now.y, now.age+1});
            }
            else {
                dieTrees.push_back(now);
            }
        }

        // 여름 - 죽은 나무 양분 전환
        for (int j=0; j<dieTrees.size(); j++) {
            Tree now = dieTrees[j];
            field[now.x][now.y] += now.age / 2;
        }

        // 가을 - 나무 번식
        for (int j=0; j<newAliveTrees.size(); j++) {
            Tree now = newAliveTrees[j];
            if (now.age % 5 == 0) {
                // 인접 8칸에 나이 1인 나무 생성
                for (int s=0; s<DIR_MAX; s++) {
                    int mx = now.x + dx[s];
                    int my = now.y + dy[s];
                    if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
                    babyTrees.push_front({mx, my, 1});
                }
            }
        }

        // 겨울
        for (int j=0; j<n; j++) {
            for (int s=0; s<n; s++) {
                field[j][s] += fertilizer[j][s];
            }
        }
        while (!babyTrees.empty()) {
            newAliveTrees.push_front(babyTrees.back());
            babyTrees.pop_back();
        }
        aliveTrees = newAliveTrees;
    }
    cout << aliveTrees.size() << '\n';

    return 0;
}