#include <iostream>
#include <vector>
using namespace std;

int findLeafNode(int parent);

int n, removeNode, rootNode, res;
vector<int> v[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1) {
            rootNode = i;
            continue;
        }
        v[tmp].push_back(i);
    }
    cin >> removeNode;
    
    if (removeNode == rootNode) {
        cout << 0 << "\n";
        return 0;
    }
    res = findLeafNode(rootNode);
    cout << res << "\n";

    return 0;
}

int findLeafNode(int parent) {
    int res = 0;
    if (v[parent].empty()) {
        return 1;
    }
    else if (v[parent].size() == 1 && v[parent][0] == removeNode) {
        return 1;
    }
    for (int i=0; i<v[parent].size(); i++) {
        if (v[parent][i] == removeNode) continue;
        res += findLeafNode(v[parent][i]);
    }
    return res;
}
