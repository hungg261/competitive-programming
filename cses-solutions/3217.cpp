#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
int n, res[MAXN + 5][MAXN + 5];

struct state{
    int x, y, moves;
};

void bfs(){
    queue<state> que;
    que.push({1, 1, 0});

    while(!que.empty()){
        int x = que.front().x, y = que.front().y,
            moves = que.front().moves;
        que.pop();

        if(moves >= res[x][y]) continue;
        res[x][y] = moves;

        for(int d = 0; d < 8; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n){
                que.push({nx, ny, moves + 1});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    memset(res, 63, sizeof res);
    bfs();

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
