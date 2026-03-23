#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;

const int MAX=2e5;
int n,m;
pii a[MAX+1];

bool op(pii&a,pii&b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

int dp[MAX+1],ans=0;
void solve(){
    dp[ans++]=a[0].second;
    for(int i=1;i<m;++i){
        if(dp[ans-1]<a[i].second){
            dp[ans++]=a[i].second;
        }
        else{
            int l=0,h=ans-1,res=ans-1;
            while(l<=h){
                int mid=(l+h)/2;
                if(dp[mid]>=a[i].second){
                    h=mid-1;
                    res=mid;
                }
                else l=mid+1;
            }
            
            dp[res]=a[i].second;
        }
        // for(int i=0;i<ans;++i)cerr<<dp[i]<<' ';cerr<<'\n';
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+m,op);
    // for(int i=0;i<m;++i){
    //     cerr<<a[i].first<<' '<<a[i].second<<'\n';
    // }cerr<<'\n';
    
    solve();
    return 0;
}
