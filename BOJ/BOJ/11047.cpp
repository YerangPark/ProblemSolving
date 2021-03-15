#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int i,k,n,cnt=0;
    vector <int> v;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    while(k>0){
        if(k/v.back()>0){
            cnt+=k/v.back();
            k=k%v.back();
        }
        v.pop_back();
    }
    v.clear();
    printf("%d",cnt);
}
