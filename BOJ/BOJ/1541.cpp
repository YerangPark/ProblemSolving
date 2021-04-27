#include <iostream>
#include <string>
using namespace std;

int n=1, m;
int num[51];
string s,tmp;
int idx=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(i==s.length()-1) { //맨 마지막이면
            tmp+=s[i];
            num[idx++] = stoi(tmp);
            break;
        }
        //맨 마지막이 아니고, 숫자면
        if(s[i]!='+'&&s[i]!='-'){
            tmp+=s[i];
        }else{ //맨 마지막이 아니고 기호면
            num[idx++]=stoi(tmp);
            tmp.clear();
            tmp+=s[i];
        }
    }
    int sum=0;
    int tmpSum=0;
    bool isTest=false;
    for(int i=0;i<idx;i++){
        if(isTest){
            //괄호테스트 중 양수/음수 경우
            if(num[i]>0){
                tmpSum-=num[i];
            }
            else{
                sum+=tmpSum;
                tmpSum=num[i];
            }
            //마지막 항이면
            if(i==idx-1){
                sum+=tmpSum;
            }
        }
        else {
            //괄호 아닌 경우
            if (num[i] > 0) {
                sum+=num[i];
            }
            else{
                isTest=true;
                tmpSum=num[i];
                if(i==idx-1){
                    sum+=tmpSum;
                }
            }
        }
    }
    cout<<sum<<'\n';

    return 0;
}
