/******************************************************************************
Link: https://cses.fi/problemset/task/1689
Code: 1689
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-29-00.28.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int MAX = 8;

bool bound(int x, int y){ return 1 <= x && x <= MAX && 1 <= y && y <= MAX; }

int influence(int x, int y){
    int cnt = 0;
    for(int d = 0; d < 8; ++d){
        int nx = x + dx[d], ny = y + dy[d];
        if(bound(nx, ny)) ++cnt;
    }
    return cnt;
}

int mark[MAX + 1][MAX + 1];
int Time;
bool dfs(int x, int y){

    mark[x][y] = ++Time;
    if(Time == MAX * MAX) return true;

    vector<pair<int, int>> nxt;
    for(int d = 0; d < 8; ++d){
        int nx = x + dx[d], ny = y + dy[d];
        if(bound(nx, ny) && mark[nx][ny] == 0) nxt.emplace_back(nx, ny);
    }
    sort(begin(nxt), end(nxt), [](auto& x, auto& y){
            return influence(x.first, x.second) < influence(y.first, y.second);
         });

    for(const pair<int, int>& p: nxt){
        if(dfs(p.first, p.second)){
            return true;
        }
    }

    mark[x][y] = 0;
    --Time;
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1689.INP","r",stdin);
    //freopen("1689.OUT","w",stdout);

    int x, y;
    cin >> y >> x;

    dfs(x, y);
    for(int i = 1; i <= MAX; ++i){
        for(int j = 1; j <= MAX; ++j){
            cout << mark[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
