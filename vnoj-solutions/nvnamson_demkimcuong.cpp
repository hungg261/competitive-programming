#include<bits/stdc++.h>
using namespace std;

const int MAX=3000;
string board[MAX+1];
bool mark[MAX+1][MAX+1];
int n,m,prefix[MAX+1][MAX+1];

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y){
    if(mark[x][y]){
        return;
    }
    mark[x][y]=true;
    
    for(int d=0;d<4;++d){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&board[nx][ny]=='.'&&!mark[nx][ny]){
            dfs(nx,ny);
        }
    }
}

bool check(int i,int j){
    int height=0;
    for(int h=i;;++h){
        if(board[h][j]=='.'){
            ++height;
        }
        else break;
    }
    if(board[i-1][j]!='#'||board[i+height][j]!='#')return false;
    
    if(height%2==0)return false;
    for(int h=1;h<=(height+1)/2;++h){
        int low=j-h+1,high=j+h-1;
        if(low<1||high>m||board[i][low-1]!='#'||board[i][high+1]!='#')return false;
        
        for(int u=low;u<=high;++u){
            if(board[i][u]!='.'){
                return false;
            }
        }
        ++i;
    }
    for(int h=height/2;h>=1;--h){
        int low=j-h+1,high=j+h-1;
        if(low<1||high>m||board[i][low-1]!='#'||board[i][high+1]!='#')return false;
        
        for(int u=low;u<=high;++u){
            if(board[i][u]!='.'){
                return false;
            }
        }
        ++i;
    }
    
    return true;
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(board[i][j]=='.'&&!mark[i][j]){
                if(check(i,j)){
                    ++ans;
                }
                // cerr<<i<<' '<<j<<": "<<check(i,j)<<'\n';
                dfs(i,j);
            }
        }
    }
    
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j){
    //         cout<<mark[i][j]<<' ';
    //         // cout<<board[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>board[i];
        board[i]=' '+board[i];
    }
    
    solve();
    return 0;
}
