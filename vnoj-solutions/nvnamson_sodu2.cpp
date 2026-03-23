#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5;
int a[MAX],n;
bool mark[1000005];

void solve(){
    int ans=0;
    int MAXVAL=a[n-1]*2;
    for(int i=0;i<n;++i){
        for(int j=a[i]*2;j<=MAXVAL;j+=a[i]){
            int cur=*(lower_bound(a+i,a+n,j)-1);
            ans=max(ans,cur%a[i]);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int len;
    cin>>len;
    while(len--){
        int cur;
        cin>>cur;
        
        if(mark[cur]==true)continue;
        mark[cur]=true;
        
        a[n++]=cur;
    }
    sort(a,a+n);
        
    solve();
    return 0;
}
