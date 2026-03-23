#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

int solve(int n){
    int r=1,c=0;
    while(n%2==0){
        n/=2;
        c++;
    }
    r*=c+1;
    for(int i=3;i<=sqrt(n);i+=2){
        c=0;
        while(n%i==0){
            n/=i;
            c++;
        }
        r*=c+1;
    }
    if(n>1)r*=2;
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("BAI.INP","r",stdin);freopen("BAI.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<solve(n)<<endl;
    }

    return 0;
}