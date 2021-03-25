#include <iostream>
#include <string>
#include <vector>
using namespace std;
int al[26],i,j,n,cnt=0;
char beforeAl;
string str;
bool isGroup;
int main(void){
    cin>>n;
    for(i=0;i<n;i++){
        isGroup=true;
        cin>>str;
        for(j=0;j<str.length();j++){
            if(j!=0&&str[j]!=beforeAl&&al[str[j]-97]) isGroup=false;
            al[str[j]-97]++;
            beforeAl=str[j];
        }
        if(isGroup) cnt++;
        if(n-i-1) for(j=0;j<26;al[j]=0,j++);
    }
    cout<<cnt<<endl;
}
