#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("av04.INP","r",stdin);freopen("av04.OUT","w",stdout);
    int n,q,s=0,c=0;cin>>n;
    while(n--){
        cin>>q;
        if(q<0)s+=q,++c;
    }
    if(c)cout<<fixed<<setprecision(2)<<(double)s/c;
    else cout<<-1;

    return 0;
}