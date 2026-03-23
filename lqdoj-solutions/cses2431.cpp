#include<bits/stdc++.h>
#define int long long
using namespace std;

const int cnt[19]={0,9,90,900,9000,90000,900000,9000000,90000000LL,900000000LL,9000000000LL,90000000000LL,900000000000LL,9000000000000LL,90000000000000LL,900000000000000LL,9000000000000000LL,90000000000000000LL,900000000000000000LL};
void solve(){
    int k;cin>>k;

    int chuso=1,boqua=0;
    while(k>chuso*cnt[chuso]){
        k-=chuso*cnt[chuso];
        boqua+=cnt[chuso];
        ++chuso;
    }

    boqua+=(k-1)/chuso+1;
    cout<<to_string(boqua)[(k-1)%chuso]<<'\n';
}

signed main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}