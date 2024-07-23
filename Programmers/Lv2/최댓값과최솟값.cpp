#include <string>
#include <vector>
#define MAX_INT 2147483647
#define MIN_INT -2147483647

using namespace std;

string solution(string s) {
    string answer = "";
    int min = MAX_INT, max = MIN_INT;
    int pos = 0;
    
    while (pos != -1) {
        string tmpStr = "";
        pos = s.find(' ');
        if (pos != -1) {
            tmpStr = s.substr(0, pos);
            s = s.substr(pos+1, s.length()-pos);
        }
        else {
            tmpStr = s;
        }
        
        int tmpNum = stoi(tmpStr);
        if (tmpNum < min) min = tmpNum;
        if (tmpNum > max) max = tmpNum;
    }
    
    answer = (to_string(min) + " " + to_string(max));
    return answer;
}
