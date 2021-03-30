#include <iostream>
#include <map>
using namespace std;
void traversal(int n, map<char,pair<char, char>>& pm, char now){
    //base case 기저 조건
    if(now=='.')
        return;
    //recursion
    //전위(-1) : 루 왼 오
    if(n==-1){
        cout<<now;
        traversal(n, pm, pm[now].first);
        traversal(n, pm, pm[now].second);
    }
    //중위(0) : 왼 루 오
    if(n==0){
        traversal(n, pm, pm[now].first);
        cout<<now;
        traversal(n, pm, pm[now].second);
    }
    //후위(1) : 왼 오 루
    if(n==1){
        traversal(n, pm, pm[now].first);
        traversal(n, pm, pm[now].second);
        cout<<now;
    }
    return;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    map<char,pair<char, char>> pm;
    
    int n,i;
    char now,left,right;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>now>>left>>right;
        pm[now]={left, right};
    }
    // 전위 : -1, 중위 : 0, 후위 : 1
    traversal(-1, pm, 'A'); cout<<'\n';
    traversal(0, pm, 'A'); cout<<'\n';
    traversal(1, pm, 'A'); cout<<'\n';
}
