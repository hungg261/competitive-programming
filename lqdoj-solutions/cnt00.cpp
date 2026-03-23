#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("cnt00.INP","r",stdin);freopen("cnt00.OUT","w",stdout);
    int n,q,x,c=0;cin>>n>>x;
    while(cin>>q&&--n)c+=q==x;
    cout<<c;

    return 0;
}