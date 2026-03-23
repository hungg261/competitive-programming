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
    //freopen("19thtbdna1.INP","r",stdin);freopen("19thtbdna1.OUT","w",stdout);
    string n;cin>>n;
    int c=0;
    for(int k:n)if((k-'0')%2)++c;
    cout<<c;

    return 0;
}