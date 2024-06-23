#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

void dfs(int x, int orig);

int n;
int arr[101] = {0};
bool visited[101] = {false};
bool done[101] = {false};
vector <int> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            dfs(i, i);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto x: result) {
        cout << x << endl;
    }
}

void dfs(int x) {
    visited[x] = true;
    int nextNode = arr[x];

    if (!visited[arr[x]]) {
        dfs(nextNode);
    }
    else if (!done[nextNode]) {
        for (int i=nextNode; i!=x;) {
            result.push_back(i);
            i=arr[i];
        }
        result.push_back(x);
    }
    done[x] = true;
}
