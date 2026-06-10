#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1;
int n,A[MAX],Q[MAX]={};
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;

    int m=0;
    for(int i=0;i<n;++i){
        cin>>A[i];
        ++Q[A[i]];
        m=max(m,A[i]);
    }

    int ans=1;
    for(int i=1;i<=m;++i){
        int cnt=0;
        for(int j=i;j<=m;j+=i){
            if(Q[j]>0)cnt+=Q[j];
            if(cnt>=2)break;
        }
        if(cnt>=2)ans=max(ans,i);
    }
    cout<<ans;
    return 0;
}