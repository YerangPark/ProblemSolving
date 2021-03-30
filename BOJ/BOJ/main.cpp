#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
//#include<bits/stdc++.h>

//#define INT_MAX 2147483647
//bool compare(int a, int b) {return a>b;}
//memset(dp, -1, sizeof(dp));

//int n,m,i,j,sum=0,cnt=0,a, b,ran;

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
    //통일 아니면 4구간으로 나누기
    //좌상 우상 좌하 우하
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

/*
 쿼드트리
 (주어진 영상 모두 0이면 0, 모두 1이면 1)
 0과 1이 섞여있으면 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래
 이렇게 4개의 영상으로 나누어 압축
 4개의 영역 압축한 결과를 차례로 묶어서 괄호에 표현
 
 입력> 영상 크기 N(항상 2제곱수, 1~64)
 N*N이미지
 
 */
