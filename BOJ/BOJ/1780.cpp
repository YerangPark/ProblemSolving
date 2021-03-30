#include <iostream>
using namespace std;
int arr[2187][2187];
int i, j, n,cnt[3];
void recursion(int startX, int endX, int startY, int endY){
    //base case
    if(startX==endX&&startY==endY) {
        cnt[arr[startY][startX]+1]++;
        return;
    }
    //recursion
   bool isChange=false;
   int tmp=arr[startY][startX];
   for(int t=startY;t<=endY;t++){
       for(int p=startX;p<=endX;p++){
           if(arr[t][p]!=tmp){
               isChange=true;
               goto label;
           }
       }
   }
    label:
   //전체 통일이면
   if(!isChange){
       cnt[tmp+1]++;
   }
   //통일 아니면 9구간으로 나누기
   else{
       int varX = (endX-startX+1)/3;
       int varY = (endY-startY+1)/3;
       for(int t=0;t<3;t++){
           for(int p=0;p<3;p++){
               recursion(startX+p*varX, startX+(p+1)*varX-1,
                         startY+t*varY, startY+(t+1)*varY-1);
           }
       }
   }
   return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    //재귀 진입
    recursion(0,n-1,0,n-1);
    
    for(auto p:cnt)cout<<p<<'\n';
}

