#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5+1;
int A[MAX],P[MAX]={},n,k;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i];
        P[i+1]=P[i]+A[i];
    }

    int ans=0;
    for(int i=k;i<=n;++i){
        ans=max(ans,P[i]-P[i-k]);
    }
    cout<<ans;
    return 0;
}