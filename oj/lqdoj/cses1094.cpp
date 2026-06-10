#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=2e5+1;
int A[MAX],n;
signed main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>A[i];

    int ans=0;
    for(int i=0;i<n-1;++i){
        if(A[i]>A[i+1])
            ans+=A[i]-A[i+1],A[i+1]=A[i];
    }
    cout<<ans;
    return 0;
}