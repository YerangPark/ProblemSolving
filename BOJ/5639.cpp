#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void printTree(int start, int end) {
    if (start >= end) {
        return;
    }
    else if (start == end-1) {
        cout << v[start] << '\n';
        return;
    }

    int newStart = start + 1;
    // 현재 노드보다 더 큰 값 찾을 때까지 탐색
    for (int i=start+1; i<end; i++) {
        if (v[i] > v[start]) {
            newStart = i;
            break;
        }
    }
    // 왼
    printTree(start+1, newStart);
    // 오
    printTree(newStart, end);
    // 자신
    cout << v[start] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (cin >> n) {
        v.push_back(n);
    }

    printTree(0, v.size());

    return 0;
}