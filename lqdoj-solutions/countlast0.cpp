#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int solve(){
    int ans=0;
    for(int i=5;i<=n;i*=5)
        ans+=n/i;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        cout<<solve()<<'\n';
    }
    return 0;
}