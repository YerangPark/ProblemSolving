#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nn;
bool compare(string a, string b) {
    if (a[nn] < b[nn]) return true;
    else if (a[nn] == b[nn]) {
        int s = 0;
        while(s <= 100) { // 사전순 정렬
            if (a[s] < b[s]) return true;
            else if (a[s] > b[s]) return false;
            s++;
        }
    }
    return false;
}

vector<string> solution(vector<string> strings, int n) {
    nn = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}