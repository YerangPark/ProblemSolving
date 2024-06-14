#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int max, now, want, uAmount, dAmount;
    cin >> max >> now >> want >> uAmount >> dAmount;

    queue <pair<int, int>> gang;
    bool visit[1000001] = {false};

    gang.push(make_pair(now, 0));
    visit[now] = true;

    while(!gang.empty()) {
        int n = gang.front().first;
        int cnt = gang.front().second;
        gang.pop();
        if (n == want) {
            cout << cnt << endl;
            want = -1;
            break;
        }

        for (int i=0; i<2; i++) {
            int mn = n;
            switch(i) {
                case 0 :
                    mn += uAmount;
                    break;
                case 1 :
                    mn -= dAmount;
                    break;
            }
            if (mn < 1 || mn > max || visit[mn]) continue;
            gang.push(make_pair(mn, cnt + 1));
            visit[mn] = true;
        }
    }
    if (want != -1) {
        cout << "use the stairs" << endl;
    }
}
