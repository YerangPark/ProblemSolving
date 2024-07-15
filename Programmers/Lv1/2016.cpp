#include <string>
#include <vector>

using namespace std;
string week[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    int day = 0;
    for (int i=0; i<a; i++) {
        if (i == a-1) {
            day += b;
        }
        else {
            day += days[i];
        }
    }
    
    return week[day%7];;
}