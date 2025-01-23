#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M; // 문서의 개수와 찾고자 하는 문서의 인덱스
        cin >> N >> M;

        queue<pair<int, int>> q; // (문서의 중요도, 문서의 인덱스)
        priority_queue<int> pq; // 중요도만 저장하는 우선순위 큐

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({priority, i});
            pq.push(priority);
        }

        int printOrder = 0; // 출력 순서
        while (!q.empty()) {
            int currentPriority = q.front().first;
            int currentIndex = q.front().second;
            q.pop();

            // 현재 문서의 중요도가 가장 높은지 확인
            if (currentPriority == pq.top()) {
                pq.pop(); // 해당 중요도를 처리
                printOrder++; // 출력 순서를 증가

                // 찾고자 하는 문서가 인쇄된 경우
                if (currentIndex == M) {
                    cout << printOrder << '\n';
                    break;
                }
            } else {
                // 중요도가 더 높은 문서가 있다면 뒤로 이동
                q.push({currentPriority, currentIndex});
            }
        }
    }

    return 0;
}
