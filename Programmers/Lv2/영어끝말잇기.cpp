#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int person = 1;
    int order = 0;
    bool isEnd = false;
    char lastAlpha = words[0][words[0].length()-1];
    map<string, bool> m;
    m.insert({words[0], true});

    for (int i=1; i<words.size(); i++) {
        if (m.find(words[i]) != m.end() || lastAlpha != words[i][0]) {
            isEnd = true;
            break;
        }
        else {
            m.insert({words[i], true});
            lastAlpha = words[i][words[i].length()-1];
        }
        if (person == n-1) order++;
        person = (person + 1) % n;
    }
    if (isEnd) {
        answer.push_back(person + 1);
        answer.push_back(order + 1);
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}