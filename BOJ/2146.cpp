#include <iostream>
#include <queue>
#include <algorithm> // for sort()
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
struct Axis {
    int x;
    int y;
    int cnt;
};

int n;
int arr[100][100] = {0};
vector <int> result;

void setIslandId();
int findBridge();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    setIslandId();
    int min = findBridge();
    cout << min << endl;
}

void setIslandId() {
    int islandId = 1;
    bool idVisited[100][100] = {false};
    queue<pair<int, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] == 1 && !idVisited[i][j]) {
                q.push(make_pair(i, j));
                idVisited[i][j] = true;
                arr[i][j] = islandId;
                while(!q.empty()) {
                    int xx = q.front().first;
                    int yy = q.front().second;
                    q.pop();
                    
                    for (int k=0; k<4; k++) {
                        int mx = xx + dx[k];
                        int my = yy + dy[k];
                        if (mx < 0 || mx >= n || my < 0 || my >= n || idVisited[mx][my] || !arr[mx][my]) continue;
                        idVisited[mx][my] = true;
                        arr[mx][my] = islandId;
                        q.push(make_pair(mx, my));
                    }
                }
                islandId++;
            }
        }
    }
}

int findBridge() {
    bool visited[100][100] = {false};
    int min = 10001;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (visited[i][j] || !arr[i][j]) continue;
            int nonShoreCnt = 0;
            // 사방에 바다가 없으면 다리 체크할 필요가 없으므로
            for (int k=0; k<4; k++) {
                int mi = i + dx[k];
                int mj = j + dy[k];
                if (mi < 0 || mi >= n || mj < 0 || mj >= n || arr[mi][mj] != 0) nonShoreCnt++;
            }
            if (nonShoreCnt == 4) continue;
            
//            cout << "check start (" << i << ", " << j << ")\n";
            bool visitedLoad[100][100] = {false};
            bool findBridge = false;
            queue <Axis> q;
            q.push(Axis {i, j, 0});
            visited[i][j] = true;
            visitedLoad[i][j] = true;

            while(!q.empty()) {
                int x = q.front().x;
                int y = q.front().y;
                int cnt = q.front().cnt;
                q.pop();
                
                if (arr[x][y] != 0 && arr[x][y] != arr[i][j]) {
                    findBridge = true;
                    cnt -= 1;
//                    cout << " bridge find! (" << x << ", " << y << "), len : " << cnt << "\n";
                    min = (min > cnt) ? cnt : min;
                    break;
                }
                
                for (int k=0; k<4; k++) {
                    int mx = x + dx[k];
                    int my = y + dy[k];
                    if (mx < 0 || mx >= n || my < 0 || my >= n || visitedLoad[mx][my]) continue;
                    visitedLoad[mx][my] = true;
                    q.push(Axis {mx, my, cnt+1});
                }
            }
            
        }
    }
    return min;
}
