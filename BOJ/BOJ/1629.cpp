#include <iostream>
typedef long long ll;
using namespace std;
int a, b, c;
int mul(int k, int cnt) {
    if (cnt == 0) return 1;
    int temp = mul(k, cnt / 2);
    int result = (1ll * temp * temp) % c;
    if (cnt % 2) result = 1ll * result * k % c;
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>a>>b>>c;
    cout<<mul(a, b)<<'\n';
    return 0;
}
