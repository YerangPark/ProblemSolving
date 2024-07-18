#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int supo1[5] = {1, 2, 3, 4, 5};
int supo2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int supo3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int correct[3] = {0,};
    int m = 0;
    for (int i=0; i<answers.size(); i++) {
        if (answers[i] == supo1[i%5]) {
            correct[0]++;
        }
        if (answers[i] == supo2[i%8]) {
            correct[1]++;
        }
        if (answers[i] == supo3[i%10]) {
            correct[2]++;
        }
    }
    
    m = max({correct[0], correct[1], correct[2]});
    // 가장 높은 점수 받은 사람 찾기
    for (int i=0; i<3; i++) {
        if (correct[i] == m) answer.push_back(i+1);
    }
    
    return answer;
}