#include<bits/stdc++.h>
using namespace std;

const int MAX=3000;
int n,a[MAX];

void sub2(){
    unordered_map<int,int>mark;
    for(int i=0;i<n;++i){
        cin>>a[i];
        ++mark[a[i]];
    }
    
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ans+=mark[a[i]+a[j]];
        }
    }
    cout<<ans*2<<'\n';
}

void sub3(){
    long long ans=0;
    for(int i=1;i<=n;++i){
        ans+=(i-1)/2;
    }
    cout<<ans*2<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PTB2.INP","r",stdin);
    freopen("PTB2.OUT","w",stdout);
    cin>>n;
    if(n<=MAX)sub2();
    else sub3();
    
    return 0;
}
