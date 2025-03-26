#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int solution(string numbers) {
    map<int, int> m;
    set<int> s;
    
    const int limit = pow(10, numbers.length()) - 1;
    
    // 넘버 미리 맵에 넣어두기
    for (int i=0; i<numbers.length(); i++) {
        int number = numbers[i] - '0';
        if (m.find(number) == m.end()) {
            m.insert({number, 1});
        }
        else {
            m[number]++;
        }
    }

    // 에라토스테네스의 체 구현
    vector<int> v(limit+1);
    for (int i=2; i<=limit; i++) {
        for (int j=2; i*j<=limit; j++) {
            v[i*j] = -1;
        }
    }
    
    // 본격 만들 수 있는지 체크
    for (int i=2; i<=limit; i++) {
        map<int, int> copyM;
        copyM.insert(m.begin(), m.end());
        
        if (v[i] != -1) { // 소수면서
            int num = i;
            bool isValid = true;
            while (num > 0) { // 한자리씩 체크
                int digit = num%10;
                if (copyM.find(digit) == copyM.end() || copyM[digit] == 0) {
                    // 맵에 해당 숫자 없거나 개수가 0개면 만들 수 없는 숫자
                    isValid = false;
                    break;
                }
                copyM[digit]--;
                num /= 10;
            }
            if (isValid) {
                s.insert(i);
            }
        }
    }
    
    return s.size();
}
