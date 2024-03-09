#include <iostream>
#include <string>
using namespace std;
int arr[64][64];
string str;
void quadtree(int startX, int endX, int startY, int endY){
    //base case
    if(startX>endX||startY>endY) return;
    if(startX==endX&&startY==endY) {
        str+=to_string(arr[startY][startX]);
        return;
    }
    //recursion
    bool isChange=false;
    int tmp=arr[startY][startX];
    for(int i=startY;i<=endY;i++){
        for(int j=startX;j<=endX;j++){
            if(arr[i][j]!=tmp){
                isChange=true;
                break;
            }
        }
    }
    //전체 통일이면
    if(!isChange){
        str+=to_string(tmp);
    }
    //통일 아니면 4구간으로 나누기 : 좌상 우상 좌하 우하
    else{
        str+="(";
        int varX=(endX-startX)/2+1;
        int varY=(endY-startY)/2+1;
        quadtree(startX, endX-varX, startY, endY-varY);
        quadtree(startX+varX, endX, startY, endY-varY);
        quadtree(startX, endX-varX, startY+varY, endY);
        quadtree(startX+varX, endX, startY+varY, endY);
        str+=")";
    }
    return;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    quadtree(0,n-1,0,n-1);
    cout<<str<<'\n';
}
