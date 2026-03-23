#include<bits/stdc++.h>
using namespace std;

int solve(){
    int a,b;
    cin>>a>>b;
    
    return (a<=1&&b<=2)||(a<=2&&b<=1);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        cout<<(solve()?"Yes":"No")<<'\n';
    }
    return 0;
}
