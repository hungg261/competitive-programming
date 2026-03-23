#include<bits/stdc++.h>
using namespace std;

const int MAX=801;
int A[MAX][MAX],mark[2000005],OFFSET=1000001,n,m,k;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)cin>>A[i][j];
    
    int ans=0,sum=0,cnt=0,smal=1e9,sumans=1e9;
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            sum+=A[i][j];
            if(mark[A[i][j]+OFFSET]==0)++ans;
            ++mark[A[i][j]+OFFSET];
        }
    }
    sumans=sum;
    smal=ans;
    ans=sum=0;
    
    for(int i=0;i<n-k+1;++i){
        memset(mark,0,sizeof(mark));
        ans=0,sum=0;
        for(int j=0;j<m;++j){
            for(int q=0;q<k;++q){
                if(mark[A[i+q][j]+OFFSET]==0)++ans;
                ++mark[A[i+q][j]+OFFSET];
                sum+=A[i+q][j];
                if(j>=k){
                    --mark[A[i+q][j-k]+OFFSET];
                    sum-=A[i+q][j-k];
                    if(mark[A[i+q][j-k]+OFFSET]==0)--ans;
                }
            }
            if(j>=k-1&&ans<=smal){
                if(ans==smal&&sum<sumans)sumans=sum;
                else if(ans<smal)sumans=sum;
                smal=ans;
            }
            // cout<<i<<' '<<j<<' '<<ans<<' '<<sum<<' '<<smal<<' '<<sumans<<'\n';
        }
    }
    // cout<<'\n';
    cout<<sumans;
    return 0;
}
