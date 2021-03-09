#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility> //pair
//#include<bits/stdc++.h>
//#define INT_MAX 2147483647

using namespace std;

bool compare(int a, int b) {return a>b;}
int n,m,i,j,sum=0,cnt=0;
int main(void) {
    string str;
    while(1){
        getline(cin,str);
        if(str=="END") break;
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    /*
    char s[500], s2[500];
    cin.getline(s,500,'END');
    int len=0;
    while(s[len]) len++;
    s[len]=s[len-1]='\0';
    len-=2;
    for(i=0;i<len;i++){
        s2[i]=s[len-i-1];
    }
    printf("\n\n");
    for(i=0;i<len;i++){
        if(i==0 && s2[i]=='\n') continue;
        printf("%c",s2[i]);
    }
    //cout<<s2;
    */
    return 0;
}

/*
 
 */
