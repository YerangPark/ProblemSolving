#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int frontIdx = 0;
    int backIdx = people.size()-1;

    sort(people.begin(), people.end());
    while(frontIdx <= backIdx) {
        if (people[frontIdx] + people[backIdx] <= limit) {
            frontIdx++;
            backIdx--;
            answer++;
        }
        else {
            backIdx--;
            answer++;
        }
    }

    return answer;
}
