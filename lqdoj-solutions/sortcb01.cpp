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
    //freopen("sortcb01.INP","r",stdin);freopen("sortcb01.OUT","w",stdout);
    int n;cin>>n;
    int A[n];inp(A,n);
    sort(A,A+n,greater<int>());

    for(int k:A)cout<<k<<' ';
    return 0;
}