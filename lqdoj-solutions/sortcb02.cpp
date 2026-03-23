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
    //freopen("sortcb02.INP","r",stdin);freopen("sortcb02.OUT","w",stdout);
    int n,k;cin>>n>>k;
    int A[n];inp(A,n);
    sort(A,A+n);
    cout<<A[k-1];

    return 0;
}