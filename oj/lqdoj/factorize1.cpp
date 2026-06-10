#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1;
int A[MAX],k=0;

int solve(int n){
    int ans=1,c=0;
    while(n%2==0)n/=2,++c;
    if(c)ans*=c;

    for(int i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0)n/=i,++c;
        if(c)ans*=c;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<solve(n)<<'\n';
    }
    return 0;
}