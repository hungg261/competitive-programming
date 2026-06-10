#include<bits/stdc++.h>
using namespace std;

const int MAXN=300;
const int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
int board[MAXN][MAXN],n,m;
bool mark[MAXN][MAXN];

void loang(int x,int y,int w){
    queue<tuple<int,int,int>>que;
    que.push({x,y,w});
    mark[x][y]=true;
    
    while(!que.empty()){
        int x,y,w;
        tie(x,y,w)=que.front();
        que.pop();
        
        if(w==0)continue;
        board[x][y]+=w;
        
        for(int d=0;d<8;++d){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&!mark[nx][ny]){
                que.push({nx,ny,w-1});
                mark[nx][ny]=true;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    while(m--){
        int x,y,w;
        cin>>x>>y>>w;
        
        memset(mark,0,sizeof mark);
        //??????!! wtf is wrong with me?
        loang(x,y,w);
    }
    
    int res=0;
    for(int i=0;i<n;++i){
        res=max(res,*max_element(board[i],board[i]+n));
    }
    
    cout<<res<<'\n';
    return 0;
}
