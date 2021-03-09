#include <iostream>
#include <algorithm>
#include <utility> //pair
#include <vector>

using namespace std;

bool compare(int a, int b) {return a>b;}
int n,m,i,j,sum=0;
int main(void) {
    vector<int> v;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&j);
        if(j<=m) v.push_back(j);
    }
    int size=v.size();
    if(v[size-1]==m){
        printf("1");
        return 0;
    }
    
    
}
/*
 동전 종류 n개.
 동전 개많음.
 가치의 합을 m로 만들거임.
 동전 개수 최솟값은?
 
 입력 >> n m
        가치 오름차순으로 입력됨...
 ================================
 
 오름차순으로 값비싼 동전부터 검사 들어가야 함.
 2개로 가능한가 검색 : v[n-1]과 n-2, n-3 ...0
                  v[n-2]와 n-3, n-4 ...0
                  ...
                  v[1]과 0
 3개로 가능한가 검색
 ...
 n개로 가능한가 검색
 */
