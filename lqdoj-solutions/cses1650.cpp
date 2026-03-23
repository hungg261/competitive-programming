#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5;
int prefix[MAXN+1],n;

void solve(){
    int a,b;
    cin>>a>>b;

    cout<<(prefix[b]^prefix[a-1])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>n>>t;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        prefix[i]=prefix[i-1]^cur;
    }

    while(t--){
        solve();
    }
    return 0;
}