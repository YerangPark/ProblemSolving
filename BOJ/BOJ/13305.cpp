#include <iostream>
using namespace std;
int n;
long long d[100001];
long long l[100001];
long long oil=0, price=0;
long long tmpDist=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;i++) cin>>d[i];
    for(int i=0;i<n;i++) cin>>l[i];

        //다음 노드로 이동할 기름이 없으면 현재 노드에서 얼마나 충전해야될지 기록
    for(int i=0;i<n-1;i++){
        if(d[i]>oil) {
            int idx=i+1;
            tmpDist=d[i];
            while(1){
                //현재 도시가 다음 도시보다 기름이 저렴하면
                if(l[idx]>l[i]&&idx<n){
                    tmpDist+=d[idx++];
                }
                else break;
            }
            oil+=tmpDist-d[i];
            price+=tmpDist*l[i];
            //비용 계산, 기름 넣고 다음 노드로 이동.
        }else{
            //기름이 있으면 기름 소비 후 걍 감. -> 반례 고려 해야됨!!
            oil-=d[i];
        }
    }
    cout<<price<<'\n';
    return 0;
}
