#include<bits/stdc++.h>
using namespace std;

const int MAX=500;
int n,m,k,prefix[MAX+5][MAX+5];

void solve(){
    int ans=0;
    for(int left=1;left<=m;++left){
        for(int right=left;right<=m;++right){
            int i=1;
            int sum=0,height=0;
            for(int j=1;j<=n;++j){
                sum+=prefix[j][right]-prefix[j][left-1];
                
                while(sum>k){
                    sum-=prefix[i][right]-prefix[i][left-1];
                    ++i;
                }
                
                height=max(height,j-i+1);
            }
            
            ans=max(ans,(right-left+1)*height);
        }
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        string line;
        cin>>line;
        for(int j=1;j<=m;++j){
            prefix[i][j]=prefix[i][j-1]+(line[j-1]-'0');
        }
    }
    
    solve();
    return 0;
}
