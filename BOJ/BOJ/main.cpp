#include <iostream>
#include <string>
using namespace std;
#include <cstdio>   //putchar() 에스터42, 공백 32, 개행 10
#include <cmath>     //abs()

int n, minY=1989, maxY=2011, minM, maxM, minD, maxD, d,m,y,i;
string minN, maxN, Na;

int main(void){
    for(i=scanf("%d",&n);i<=n;i++){
        cin>>Na>>d>>m>>y;
        if(y<maxY||(y==maxY&&maxM>m)||(y==maxY&&maxM==m&&maxD>d)){
            maxY=y;
            maxN.assign(Na);
            maxM=m;
        }
        if(y>minY||(y==minY&&minM<m)||(y==minY&&minM>m&&maxD<d)){
            minY=y;
            minN.assign(Na);
            minM=m;
        }
    }
    cout << minN <<'\n'<<maxN;
}
/*
 */
