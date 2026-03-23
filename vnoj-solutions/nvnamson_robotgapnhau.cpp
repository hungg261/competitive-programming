#include<bits/stdc++.h>
using namespace std;

const int MAX=1000;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int closet[MAX][MAX],m,n;
bool a[MAX][MAX],mark[MAX][MAX];

struct state{
    int x,y,steps;
};

void bfs(){
    queue<state>que;
    que.push({0,0,0});
    
    while(!que.empty()){
        int x=que.front().x,y=que.front().y,steps=que.front().steps;
        que.pop();
        
        if(closet[x][y]!=-1)continue;
        closet[x][y]=steps;
        
        for(int d=0;d<4;++d){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&ny>=0&&nx<m&&ny<n&&!a[nx][ny]){
                que.push({nx,ny,steps+1});
            }
        }
    }
}

void solve(){
    bfs();
    // for(int i=0;i<m;++i){
    //     for(int j=0;j<n;++j){
    //         cout<<closet[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }
    
    
    queue<state>que;
    que.push({m-1,n-1,0});
    
    while(!que.empty()){
        int x=que.front().x,y=que.front().y,steps=que.front().steps;
        que.pop();
        
        if(closet[x][y]==steps){
            cout<<steps<<'\n';
            return;
        }
        
        if(mark[x][y])continue;
        mark[x][y]=true;
        
        for(int d=0;d<4;++d){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&ny>=0&&nx<m&&ny<n&&!a[nx][ny]){
                que.push({nx,ny,steps+1});
            }
        }
    }
    cout<<"#\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    memset(closet,-1,sizeof closet);
    
    solve();
    return 0;
}
