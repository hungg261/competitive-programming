#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("BAI.INP","r",stdin);freopen("BAI.OUT","w",stdout);
    int n;cin>>n;
    vector<int>A={1,n};
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            A.pb(i);if(i!=n/i)A.pb(n/i);
        }
    }
    sort(it(A));
    for(int k:A)cout<<k<<' ';
    return 0;
}