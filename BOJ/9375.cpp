#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    while(n--){
        cin>>m;
        int ans=0, cnt=0;
        multimap<string,string> cloth;
        vector<string> kind;

        while(m--){
            string str1, str2;
            cin>>str2>>str1;
            cloth.insert({str1,str2});
            if(cloth.count(str1)==1)
                kind.push_back(str1);
            cnt++;
        }
        if(kind.size()!=1) {
            int mul = 1;
            for (int i = 0; i < kind.size(); i++) {
                mul *= cloth.count(kind[i])+1;
            }
            ans+=mul-1;
        }else ans=cnt;
        cout<<ans<<'\n';
    }

    return 0;
}
