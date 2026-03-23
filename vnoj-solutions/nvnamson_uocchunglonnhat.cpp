#include<bits/stdc++.h>
using namespace std;

const int MAX=1e6,MAXVAL=1e6;
int n,a[MAX+1],mark[MAXVAL+1];

void solve(){
    int ans=1;
    
    int store[2]={};
    for(int i=2;i<=MAXVAL;++i){
        int cnt=0;
        for(int j=i;j<=MAXVAL;j+=i){
            if(mark[j]){
                if(mark[j]>=2){
                    store[0]=store[1]=j;
                    cnt+=2;
                }
                else{
                    store[0]=store[1];
                    store[1]=j;
                    ++cnt;
                }
            }
        }
        if(cnt>=2)ans=max(ans,__gcd(store[0],store[1]));
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ++mark[a[i]];
    }
    
    solve();
    return 0;
}
