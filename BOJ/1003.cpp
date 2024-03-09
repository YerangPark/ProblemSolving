#include <iostream>
using namespace std;
int d[41][2];
int n,m,i,j;
int main(void){
    d[0][0]=d[1][1]=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        //있으면 출력 하세영
        if(d[m][0]&&d[m][1]){
            printf("%d %d\n",d[m][0],d[m][1]);
            continue;
        }
        //없으면 하위 부분을 찾기~
        for(j=2;j<=40;j++){
            if(!d[j][0]&&!d[j][1]){
                d[j][0]=d[j-1][0]+d[j-2][0];
                d[j][1]=d[j-1][1]+d[j-2][1];
            }
        }
        printf("%d %d\n",d[m][0],d[m][1]);
    }
    return 0;
}
