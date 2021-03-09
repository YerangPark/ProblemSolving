#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility> //pair
//#include<bits/stdc++.h>
//#define INT_MAX 2147483647

using namespace std;


/*
 영어 알파벳을 13글자씩 밀어서 암호를 생성한다.
 대문자는 대문자로 밀어야 하고, 소문자는 소문자로 밀기!
 */

bool compare(int a, int b) {return a>b;}
int n,m,i,j,sum=0,cnt=0;
int main(void){
    scanf("%d",&n);
    if(n%2==0) printf("YES");
    else printf("NO");
    return 0;
    
}

