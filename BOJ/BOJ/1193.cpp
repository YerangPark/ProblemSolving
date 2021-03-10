#include <iostream>
using namespace std;
int n,m,i,j,sum=0,cnt=0,a,b,ran;
int main(void){
    scanf("%d",&n);
    i=j=m=cnt=1;
    cnt=1;
    while(cnt!=n&&n!=1){
        j++; cnt++;
        if(cnt==n) goto label;

        for(a=0;a<m;a++){
            i++; j--;
            cnt++;
            if(cnt==n) goto label;
        } m++;
        
        i++; cnt++;
        if(cnt==n) goto label;
        
        for(a=0;a<m;a++){
            i--; j++; cnt++;
            if(cnt==n) goto label;
        } m++;
    }
    label:
    printf("%d/%d",i,j);
    return 0;
}
