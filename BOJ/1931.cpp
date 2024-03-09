#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second==b.second) return a.first < b.first;
    return a.second<b.second;
}
int main(void){
    vector <pair<int, int>> v;
    int n,i,cnt=1, st, en;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&st,&en);
        v.push_back(make_pair(st,en));
    }
    sort(v.begin(),v.end(),compare);
    en=v[0].second;
    for(i=1;i<n;i++){
        if(en<=v[i].first){
            en=v[i].second;
            cnt++;
            printf("pick(%d, %d)\n",v[i].first,v[i].second);
        }
    }
    printf("%d",cnt);
}
