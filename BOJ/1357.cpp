#include <iostream>
using namespace std;
string reverse(string str){
    string tmp;
    while(!str.empty()){
        tmp.push_back(str[str.length()-1]);
        str.pop_back();
    }
    return tmp;
}
int main(void) {
    string str1, str2;
    cin>>str1>>str2;
    cout<<stoi(reverse(to_string(stoi(reverse(str1))+stoi(reverse(str2)))));
    return 0;
}
