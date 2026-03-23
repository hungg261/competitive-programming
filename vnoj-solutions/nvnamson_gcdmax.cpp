#include<bits/stdc++.h>
#define left sussy
#define right baka
#define int long long
using namespace std;

const int MAXN=1e5;
int a[MAXN+1],n,k;

int left[MAXN+1],right[MAXN+1];
void compute(){
    left[1]=a[1];
    for(int i=2;i<=n;++i){
        if(i%k==1){
            left[i]=a[i];
        }
        else left[i]=__gcd(left[i-1],a[i]);
    }
    
    right[n]=a[n];
    for(int i=n-1;i>=1;--i){
        if(i%k==1){
            right[i]=a[i];
        }
        else right[i]=__gcd(right[i+1],a[i]);
    }
}

int query(int i,int j){
    return __gcd(left[j],right[i]);
}

void solve(){
    int ans=0;
    for(int i=k;i<=n;++i){
        ans=max(ans,query(i-k+1,i));
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    compute();
    solve();
    return 0;
}
