#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int h[3],b[2];
    scanf("%d %d %d %d %d",&h[0],&h[1],&h[2],&b[0],&b[1]);
    sort(h,h+3);
    sort(b,b+2);
    printf("%d",h[0]+b[0]-50);
    return 0;
}
