#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(char k){
    return ('a'<=k&&k<='z')||('A'<=k&&k<='Z');
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    getline(cin,s);
    
    for(char k:s){
        if(check(k)){
            cout<<k;
        }
    }
    return 0;
}
