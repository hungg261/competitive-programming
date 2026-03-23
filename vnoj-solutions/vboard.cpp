#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=500;
int a[MAXN+1][MAXN+1],n,prefix[2][MAXN+1][MAXN+1];
int color[MAXN+1][MAXN+1];

void compute(int type){
    for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
            prefix[type][i][j]=prefix[type][i][j-1]+prefix[type][i-1][j]-prefix[type][i-1][j-1];
            if(color[i][j]==type){
                prefix[type][i][j]+=a[i][j];
            }
        }
    }
}

int get(int x1,int y1,int x2,int y2,int type){
    return prefix[type][x2][y2]-prefix[type][x1-1][y2]-prefix[type][x2][y1-1]+prefix[type][x1-1][y1-1];
}

void solve(){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    
    cout<<llabs(get(x1,y1,x2,y2,0)-get(x1,y1,x2,y2,1))<<'\n';
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
        
        color[i][1]=(i+1)%2;
        for(int j=2;j<=n;++j){
            color[i][j]=(color[i][j-1]+1)%2;
        }
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cerr<<color[i][j]<<' ';
        }
        cerr<<'\n';
    }
    
    compute(0);
    compute(1);
    
    int q;
    cin>>q;
    
    while(q--){
        solve();
    }
    return 0;
}
