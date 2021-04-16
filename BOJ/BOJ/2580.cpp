#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt=0;
int arr[10][10];
bool isEnd=false;
void printArr(int arr[][10]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
}
void recursion(vector<pair<int,int>>& pv){
    if(isEnd) return;
    //base case
    if(pv.empty()){
        printArr(arr);
        isEnd=true;
        return;
    }
    //recursion
    //그 빈 자리에 올 수 있는 놈들 저장용 배열
    int prob[9]={1,2,3,4,5,6,7,8,9};
    //가로 검사
    int x, y;
    y=pv.back().first; x=pv.back().second;
    for(int i=0;i<9;i++){
        if(x==i||arr[y][i]==0){
            continue;
        }
        prob[arr[y][i]-1]=0;
    }
    //세로 검사
    for(int i=0;i<9;i++){
        if(y==i||arr[i][x]==0){
            continue;
        }
        prob[arr[i][x]-1]=0;
    }
    
    //네모 영역 검사. 범위 시작지점 x, y를 각각 boxX, boxY라고 한다.
    int boxY,boxX;
    boxY=(y/3)*3;
    boxX=(x/3)*3;
    for(int i=boxY;i<boxY+3;i++){
        for(int j=boxX;j<boxX+3;j++){
            if((y==i||x==j)||arr[i][j]==0) continue;
            prob[arr[i][j]-1]=0;
        }
    }
    
    //검사가 끝나면 prob배열에 가능한 놈들만 0이 아닌 값으로 남아있을 거임.
    //들어갈 수 있는 놈들을 차례대로 넣었다 빼면서 재귀~!~!~!~!
    for(int i=0;i<9;i++){
        if(prob[i]==0) continue;
        arr[y][x]=prob[i];
        pv.pop_back();
        recursion(pv);
        arr[y][x]=0;
        pv.push_back(make_pair(y,x));
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,int>> v;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>n;
            arr[i][j]=n;
            if(n==0){
                v.push_back(make_pair(i, j));
            }
        }
    }
    recursion(v);
}
