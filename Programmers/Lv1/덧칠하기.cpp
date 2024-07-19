#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for (int i=0; i<section.size(); i++){
        int start = section[i];
        while (i != section.size()-1 && section[i+1] - start < m) {
            i++;
        }
        answer++;
    }
    
    return answer;
}