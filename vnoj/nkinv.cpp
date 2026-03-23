#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=6e4,MAXVAL=6e4;
int n,BIT[MAXVAL+5];

void update(int idx,int value){
    while(idx<=MAXVAL){
        BIT[idx]+=value;
        idx+=idx&(-idx);
    }
}

int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        
        ans+=get(MAXVAL)-get(cur);
        update(cur,1);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    solve();
    return 0;
}
