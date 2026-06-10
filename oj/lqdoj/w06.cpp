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
    int a,b;cin>>a>>b;
    for(int i=1;i<=__gcd(a,b);i++){
        if(a%i==0&&b%i==0){
            cout<<i<<' ';
        }
    }
    return 0;
}