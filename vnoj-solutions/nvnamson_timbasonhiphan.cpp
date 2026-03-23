#include<bits/stdc++.h>
using namespace std;

int toDec(string s){
    int res=0;
    for(char k:s){
        (res*=2)+=k%2;
    }
    return res;
}

bool xuli(string s){
    string a=s.substr(0,8),b=s.substr(8,8),c=s.substr(16,8);
    int x=toDec(a),y=toDec(b),z=toDec(c);
    if(x+1==y&&y+1==z){
        cout<<a<<'\n'<<b<<'\n'<<c<<'\n';
        return true;
    }
    return false;
}

void solve(string s){
    int n=s.size();
    for(int i=0;i<=n-24;++i){
        if(xuli(s.substr(i,24))){
            break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("xau.inp","r",stdin);
    freopen("xau.out","w",stdout);
    string s;
    cin>>s;
    
    solve(s);
    return 0;
}
