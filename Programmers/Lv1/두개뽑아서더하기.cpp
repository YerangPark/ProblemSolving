#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool b[201] = {false};
    int len = numbers.size();
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            int val = numbers[i] + numbers[j];
            if (b[val]) continue;
            b[val] = true;
            answer.push_back(val);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}