#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0, size = babbling.size();
    vector<string> available = {"aya", "ye", "woo", "ma"};
    
    for (int i=0; i<size; i++) {
        int beforeIdx = -1;
        for (int j=0; j<4; j++) {
            if (babbling[i].find(available[j]) != string::npos) {
                int index = babbling[i].find(available[j]); // 해당 문자의 시작 인덱스 반환
                // cout << "before : " << beforeIdx << " / now : " << index << endl;
                if (beforeIdx != -1 && index == beforeIdx+1) continue;
                babbling[i].erase(index, available[j].length());
                babbling[i].insert(index, ".");
                beforeIdx = index;
                j--;
                // FIXME: 특정 단어 erase 전에는 떨어져 있었는데, 제거 후에 붙어버리면 연속된걸로 취급됨.
                // 띄어쓰기를 삽입하거나.. 점을 삽입하거나 한 뒤에 마지막에 제거하면 될 듯?
            }
            else {
                beforeIdx = -1;
            }
            // 연속은 아니되, 떨어져있는 같은 단어는 읽어야 함.
        }
        // cout << babbling[i] << "\n";
        babbling[i].erase(remove(babbling[i].begin(), babbling[i].end(), '.'), babbling[i].end());
        if (babbling[i].length() == 0) answer++;
    }
    return answer;
}