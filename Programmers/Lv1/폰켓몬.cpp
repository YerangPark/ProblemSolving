#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    bool b[200001] = {false};
    for (int i=0; i<nums.size() && answer < nums.size()/2; i++) {
        if (!b[nums[i]]) {
            b[nums[i]] = true;
            answer++;
        }
    }
    return answer;
}