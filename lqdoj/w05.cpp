#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

auto solve(int n){
    int r=0,s=0;
    while(n>0){
        s+=n%10;
        r++;
        n/=10;
    }
    return make_pair(r,s);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("BAI.INP","r",stdin);freopen("BAI.OUT","w",stdout);
    int n;cin>>n;
    auto p=solve(n);
    cout<<p.st<<endl<<p.nd;
    return 0;
}