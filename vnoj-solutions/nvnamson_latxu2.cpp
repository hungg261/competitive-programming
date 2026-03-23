#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

const int MAX=1<<16;
unordered_map<int,int>res;

const int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
struct state{
    int id,mov;
    
    bool is_inside(int x,int y){
        return x>=0&&y>=0&&x<4&&y<4;
    }
    
    void flip(int x,int y){
        id^=(1<<(x*4+y));
    }
    
    void operate(int x,int y){
        for(int d=0;d<5;++d){
            int nx=x+dx[d],ny=y+dy[d];
            if(is_inside(nx,ny)){
                flip(nx,ny);
            }
        }
    }
};

void compute(){
    queue<state>que;
    que.push({0,0});

    while(!que.empty()){
        state cur=que.front();
        que.pop();
        
        if(res.count(cur.id)){
            continue;
        }
        res[cur.id]=cur.mov;

        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                cur.operate(i,j);
                ++cur.mov;
                
                que.push(cur);
                
                cur.operate(i,j);
                --cur.mov;
            }
        }
    }
}

int solve(int id){
    int ans=1e9;
    if(res.count(id))ans=min(ans,res[id]);
    if(res.count(MAX-id-1))ans=min(ans,res[MAX-id-1]);
    return ans;
}

void input(){
    int t;
    cin>>t;
    
    int a,res;
    string line;
    while(t--){
        a=0;
        for(int i=0;i<4;++i){
            cin>>line;
            
            for(int j=0;j<4;++j){
                if(line[j]=='H')a|=(1<<(i*4+j));
            }
        }
        res=solve(a);
        if(res==1e9)cout<<"Impossible\n";
        else cout<<res<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    compute();
    input();
    
    return 0;
}
