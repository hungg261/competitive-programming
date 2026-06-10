/******************************************************************************
Link: ITABLE
Code: ITABLE
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-01-09.48.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXNM=1e3;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int board[MAXNM+1][MAXNM+1],n,m;

int ESWN_to_direction(char direction){
    switch(direction){
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'W': return 3;
    }
    return -1;
}

bool checkbound(int x,int y){
    return (x>=1&&y>=1&&x<=n&&y<=m);
}

int dp[MAXNM+1][MAXNM+1];
bool dfs(int x,int y){
    if(dp[x][y]!=-1){
        return dp[x][y];
    }

    int nx=x+dx[board[x][y]],
        ny=y+dy[board[x][y]];
    if(checkbound(nx,ny)){
        dp[x][y]=1;
        dp[x][y]=dfs(nx,ny);
    }
    else dp[x][y]=0;

    return dp[x][y];
}

void solve(){
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dfs(i,j);
        }
    }

//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=m;++j){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<'\n';
//    }

    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(dp[i][j]==1){
                ++ans;
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        string line;
        cin>>line;

        for(int j=1;j<=m;++j){
            board[i][j]=ESWN_to_direction(line[j-1]);
        }
    }

    solve();
    return 0;
}
