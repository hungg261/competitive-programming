/******************************************************************************
Link: https://oj.uz/problem/view/BOI13_tracks
Code: BOI13_tracks
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-23-08.43.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 4000;
int H, W;
string arr[MAX];

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
inline int at(const pair<int, int> c){ return arr[c.first][c.second]; }
bool bound(int x, int y){ return 0 <= x && 0 <= y && x < H && y < W; }

int vis[MAX][MAX];
queue<pair<int, int>> bfs(queue<pair<int, int>> que){
    if(que.empty()) que.push({0, 0});

    queue<pair<int, int>> neighbor;
    while(!que.empty()){
        int x, y; tie(x, y) = que.front();
        que.pop();

        vis[x][y] = true;

        for(int d = 0; d < 4; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            if(bound(nx, ny) && arr[nx][ny] != '.' && !vis[nx][ny]){
                if(arr[nx][ny] == arr[x][y]) que.push({nx, ny});
                else neighbor.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }

    return neighbor;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> H >> W;
    for(int i = 0; i < H; ++i){
        cin >> arr[i];
    }

    queue<pair<int, int>> que;
    int res = 0;
    do{ que = bfs(que); ++res; } while(!que.empty());

    cout << res << "\n";

    return 0;
}
