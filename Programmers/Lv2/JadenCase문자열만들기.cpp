#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string space_delimiter = " ";
    int pos = 0;
    while (pos != string::npos) {
        pos = s.find(space_delimiter);
        string word = s.substr(0, pos);

        if (isalpha(word[0])) {
            word[0] = toupper(word[0]);
        }
        for (int i=1; i<word.size(); i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        answer += (word + " ");
        s.erase(0, pos+1);
    }

    // 마지막 스페이스 제거
    answer = answer.substr(0, answer.size()-1);

    return answer;
}