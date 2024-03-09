#include <iostream>
using namespace std;
int n,i,sum=0,a,b;
int main(void){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        sum=0;
        scanf("%d %d",&a, &b);
        if(a==1) sum+=500;
        else if(a>1&&a<4) sum+=300;
        else if(a>3&&a<7) sum+=200;
        else if(a>6&&a<11) sum+=50;
        else if(a>10&&a<16) sum+=30;
        else if(a>15&&a<22) sum+=10;
        
        if (b==1) sum+=512;
        else if(b>1&&b<4) sum+=256;
        else if(b>3&&b<8) sum+=128;
        else if(b>7&&b<16) sum+=64;
        else if(b>15&&b<32) sum+=32;
        sum*=10000;
        printf("%d\n",sum);
    }
    return 0;
}
