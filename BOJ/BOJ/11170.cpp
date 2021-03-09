#include <iostream>

using namespace std;

int arr[1000001];
int bf(int x){
    if(x==0) return 1;
    if(arr[x]==-1) return 0;
    else if(arr[x]) return arr[x];
    int t=x;
    int cnt=0;
    while(t/10>0){
        if(t%10==0)cnt++;
        t=t/10;
    }if(cnt==0)cnt=-1;
    return arr[x]=cnt;
}

bool compare(int a, int b) {return a>b;}
int n,m,i,j,sum=0,cnt=0;

int main(void){
    int a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cnt=0;
        scanf("%d %d",&a,&b);
        for(j=a;j<=b;j++){
            if(bf(j)!=-1) cnt+=bf(j);
        }
        printf("%d\n",cnt);
    }
    return 0;
}

/*
 ###### 이렇게도 가능! 남의 풀이 1
 int T;
 int main() {
     cin >> T;
     for (int i = 0; i < T; i++) {
         int N, M;
         cin >> N >> M;
         
         int cnt = 0;
         for (int j = N; j <= M; j++) {
             string test = to_string(j);
             for (int k = 0; k < test.size(); k++) {
                 if (test[k] == '0')
                     cnt++;
             }
         }
         cout << cnt << "\n";
     }
 }
 
 ##### 이 함수를 써도 가능! 남의 풀이 2
 int run(int a, int b)
 {
     int count;

     count = 0;
     for (int i = a; i <= b; i++)
     {
         int temp = i;
         if (temp == 0)
             count++;
         while (temp)
         {
             if (temp % 10 == 0)
                 count++;
             temp  /= 10;
         }
     }
     return (count);
 }
 */
