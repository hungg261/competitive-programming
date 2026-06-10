#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=3e5;
int n,M,len=0;
struct interval{
    int L,R;
} intervals[MAXN+1];

bool cmp(interval&a,interval&b){
    return a.L<b.L;
}

void solve(){
    sort(intervals,intervals+len,cmp);
    // for(int i=0;i<len;++i){
    //     cerr<<intervals[i].L<<' '<<intervals[i].R<<'\n';
    // }cerr<<'\n';
    
    int overlapped=0;
    int cur_start=intervals[0].L,
        cur_end=intervals[0].R;
    for(int i=0;i<len;++i){
        if(intervals[i].L<=cur_end){
            cur_end=max(cur_end,intervals[i].R);
        }
        else{
            overlapped+=cur_end-cur_start;
            cur_start=intervals[i].L,
            cur_end=intervals[i].R;
        }
    }
    overlapped+=cur_end-cur_start;
    cout<<M+overlapped*2<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GIAOHANG.INP","r",stdin);
    freopen("GIAOHANG.OUT","w",stdout);
    cin>>n>>M;
    for(int i=1;i<=n;++i){
        int L,R;
        cin>>L>>R;
        
        if(L>R){
            intervals[len++]={R,L};
        }
    }
    
    solve();
    return 0;
}
