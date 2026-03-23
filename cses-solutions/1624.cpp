/******************************************************************************
Link: https://cses.fi/problemset/task/1624
Code: 1624
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-18-00.09.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int N=8;
string board[N];
bool dcheo[2][2*N],cot[N];
int ways=0;

void solve(int i,int chosen){
    if(chosen==8){
        ++ways;
        return;
    }
    if(i>=N)return;

    for(int j=0;j<N;++j){
        if(board[i][j]=='.'&&!dcheo[0][i+j]&&!dcheo[1][i-j+N]&&!cot[j]){
            cot[j]=true;
            dcheo[0][i+j]=true;
            dcheo[1][i-j+N]=true;

            solve(i+1,chosen+1);

            cot[j]=false;
            dcheo[0][i+j]=false;
            dcheo[1][i-j+N]=false;
        }
    }
    solve(i+1,chosen);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1624.INP","r",stdin);
    //freopen("1624.OUT","w",stdout);
    for(int i=0;i<N;++i){
        cin>>board[i];
    }

    solve(0,0);
    cout<<ways<<'\n';
    return 0;
}

