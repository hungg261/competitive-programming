#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(int n){
    if(n==0){
        cout<<"0\n";
        return;
    }

    int ans=1e18;
    for(int i=1;i*i<=abs(n);++i){
        if(n%i==0&&(i+n/i)%2==0){
            int res=(i+n/i)/2;
            ans=min(ans,abs(res));
        }
    }
    if(ans==1e18){
        cout<<"none\n";
    }
    else cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k;
    cin>>k;

    solve(k);
    return 0;
}
