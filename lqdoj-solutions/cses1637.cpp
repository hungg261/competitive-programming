#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s;cin>>s;
    int cnt=1;
    while(s.size()>1&&s[0]!='0'){
        char i=0;
        for(char x:s){
            i=max(i,x);
        }
        s=to_string(stoi(s)-i+'0');
        ++cnt;

    }
    cout<<cnt;
    return 0;
}