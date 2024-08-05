#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i=1; i<=yellow; i++) {
        if (yellow % i !=0) continue;
        int j = yellow / i;
        if (i * j == yellow && 2 * (i + j) + 4 == brown) {
            answer.push_back(j+2);
            answer.push_back(i+2);
            break;
        }
    }
    return answer;
}
