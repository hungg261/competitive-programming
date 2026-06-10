#include<bits/stdc++.h>
using namespace std;

const int MAX=100;
int a[MAX],n,m;

void solve(){
    int l,h,ans=-1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int sum=0;
            for(int k=i;k<=j;++k){
                sum+=a[k];
            }
            
            if(j-i+1==m&&sum>ans){
                l=i;
                h=j;
                
                ans=sum;
            }
        }
    }
    for(int i=l;i<=h;++i){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("day.inp","r",stdin);
    freopen("day.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
