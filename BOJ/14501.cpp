#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Schedule {
    int time;
    int pay;
};

int dx[4] = {};
int dy[4] = {};
int n;
vector<Schedule> schedule;

int recursive(int dayNow) {
    // 종료 조건
    if (dayNow > n) {
        return 0;
    }
    Schedule today = schedule[dayNow-1];
    return max((dayNow + today.time <= n+1) ?
                today.pay + recursive(dayNow + today.time) : 0,
               recursive(dayNow + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        int time, pay;
        cin >> time >> pay;
        schedule.push_back({time, pay});
    }

    cout << recursive(1) << '\n';

    return 0;
}