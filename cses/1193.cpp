#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const char from[4] = {'R', 'D', 'L', 'U'};

bool mark[MAXN + 1][MAXN + 1];
char trace[MAXN + 1][MAXN + 1];
string a[MAXN + 5];
int n, m;

int start[2], stop[2];

void bfs(){
    queue<pair<int, int>> que;
    que.push({start[0], start[1]});

    while(!que.empty()){
        int x, y;

        tie(x, y) = que.front();
        que.pop();

        if(x == stop[0] && y == stop[1]){
            int i = x, j = y;
            string res;
            while(!(i == start[0] && j == start[1])){
                res += trace[i][j];

                int idx = find(from, from + 4, trace[i][j]) - from;
                i -= dx[idx];
                j -= dy[idx];
            }

            reverse(begin(res), end(res));

            cout << "YES\n";
            cout << (int)res.size() << '\n';
            cout << res << '\n';
            return;
        }
        if(mark[x][y]) continue;
        mark[x][y] = true;

        for(int d = 0; d < 4; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !mark[nx][ny] && a[nx][ny] != '#'){
                que.push({nx, ny});
                trace[nx][ny] = from[d];
            }
        }
    }

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        for(int j = 0; j < m; ++j){
            if(a[i][j] == 'A'){
                start[0] = i;
                start[1] = j;
            }
            else if(a[i][j] == 'B'){
                stop[0] = i;
                stop[1] = j;
            }
        }
    }

    bfs();
    return 0;
}
