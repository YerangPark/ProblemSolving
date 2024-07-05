#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
pair<int, int> v[26];

void preorder(int now);
void inorder(int now);
void postorder(int now);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        int aa = (a != '.') ? a - 'A' : -1;
        int bb = (b != '.') ? b - 'A' : -1;
        int cc = (c != '.') ? c - 'A' : -1;

        v[aa] = {bb, cc};
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
}

void preorder(int now) {
    if (now == -1) return;
    cout << (char) (now + 'A');
    preorder(v[now].first);
    preorder(v[now].second);
}

void inorder(int now) {
    if (now == -1) return;
    inorder(v[now].first);
    cout << (char) (now + 'A');
    inorder(v[now].second);
}

void postorder(int now) {
    if (now == -1) return;
    postorder(v[now].first);
    postorder(v[now].second);
    cout << (char) (now + 'A');
}
