#include <iostream>
#include <cstring>
using namespace std;
int d[21][21][21];
int w(int a, int b, int c){
    //기저
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) return w(20,20,20);
    
    //메모이제이션
    int &ret = d[a][b][c];
    if(ret!=-1)return ret;
    
    if(a<b && b<c) return ret=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return ret = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int n,m,i;
int main(void){
    memset(d, -1, sizeof(d));
    scanf("%d %d %d",&n,&m,&i);
    while(!(n==-1&&m==-1&&i==-1)){
        printf("w(%d, %d, %d) = %d\n",n,m,i,w(n,m,i));
        scanf("%d %d %d",&n,&m,&i);
    }
    return 0;
}
