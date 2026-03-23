#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5+1;
int A[MAX],P[MAX]={};
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,t;cin>>n>>t;
    for(int i=0;i<n;++i){
        cin>>A[i];
        P[i+1]=P[i]+A[i];
    }

    int ans=0,cur=0,l=0;
    for(int i=0;i<n;++i){
        cur+=A[i];
        while(cur>t){
            cur-=A[l];
            ++l;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}