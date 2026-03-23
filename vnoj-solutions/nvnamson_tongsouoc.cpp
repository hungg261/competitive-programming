#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n){
    int ans=0;
    for(int i=1;i<=n;){
        int l=i+1,h=n,res=i;
        while(l<=h){
            int mid=(l+h)/2;
            if(n/mid==n/i){
                res=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        
        // cerr<<i<<' '<<res<<": "<<n/i<<'\n';
        ans+=(n/i)*(res-i+1);
        i=res+1;
    }
    
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int L,R;
    cin>>L>>R;
    
    cout<<solve(R)-solve(L-1)<<'\n';
    return 0;
}
