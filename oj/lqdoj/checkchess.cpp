#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        cout<<(a==c||b==d?"YES\n":"NO\n");
    }
    return 0;
}