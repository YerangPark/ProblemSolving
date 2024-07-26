#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0, bin = 0;
    
    // 2진 변환 횟수, 제거된 0의 개수
    while (s != "1") {
        string tmp = "";
        for (char c : s) {
            if (c == '0') {
                zero++;
            } else {
                tmp += c;
            }
        }
        // cout << "after erase : " << tmp << endl;
        int length = tmp.length();
        s = "";
        while (length > 0) {
            s = char((length % 2) + '0') + s;
            length /= 2;
        }
        // cout << "after length : "  << s << endl;
        bin++;
    }
    answer.push_back(bin);
    answer.push_back(zero);
    
    return answer;
}