#include <iostream>
using namespace std;
int n,m,i,j,cnt=0;
int main(void) {
    string s1;
    cin>>s1>>n;
    m=(int)s1.length()*stoi(s1);
    for(j=stoi(s1);j>0;j--){
        for(i=0;i<s1.length();i++){
            if(m>n&&cnt>=n) goto label;
            else printf("%c",s1[i]);
            cnt++;
        }
    }
    label:
    return 0;
}
