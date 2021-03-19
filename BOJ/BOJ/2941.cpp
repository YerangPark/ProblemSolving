#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str;
    cin>>str;
    string croa2[8]={"c=","c-","d-","lj","nj","s=","z="};
    string croa3="dz=";
    int cnt=0;
    bool isPass=false;
    for(int i=0;i<str.size();i++){
        isPass=false;
        //croa2에 해당하는지
        for(int j=0;j<8&&!isPass;j++){
            if(!str.compare(i,2,croa2[j])){
                i++;
                isPass=true;
                break;
            }
        }
        //croa3에 해당하는지
        if(!isPass){
            if(!str.compare(i,3,croa3)){
                i+=2; isPass=true;
            }
        }
        cnt++;
    }
    printf("%d",cnt);
}
