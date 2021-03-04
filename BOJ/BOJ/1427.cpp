#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(int a, int b) {return a>b;}
int n,i,sum=0;
int main(void) {
    vector<int> v;
    scanf("%d",&n);
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v) printf("%d",i);
    return 0;
}

