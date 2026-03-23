#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int sdg(int n){
    int r=0;
    while(n>0){
        r+=n%10;
        n/=10;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("sumdigs.INP","r",stdin);freopen("sumdigs.OUT","w",stdout);
    int t,q;cin>>t;
    while(t--){
        cin>>q;
        cout<<sdg(q)<<endl;
    }

    return 0;
}