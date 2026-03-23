#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000, MAXM = 1000;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m;
string arr[MAXN + 5];
bool mark[MAXN + 5][MAXM + 5], visited[MAXN + 5][MAXN + 5];
int trace[MAXN + 5][MAXN + 5];

struct State{
    int x, y;
    char type;
};

char idx_to_dir(int d){
    switch(d){
        case 0: return 'U';
        case 1: return 'R';
        case 2: return 'D';
        case 3: return 'L';
    }

    throw runtime_error("invalid direction.");
    return -1;
}

void bfs(){
    queue<State> que;
    State start;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(arr[i][j] == 'M') que.push({i, j, 'M'});
            else if(arr[i][j] == 'A') start = {i, j, 'A'};
        }
    }

    memset(trace, -1, sizeof trace);
    que.push(start);

    while(!que.empty()){
        State cur = que.front();
        que.pop();

        if(cur.type == 'M'){
            if(mark[cur.x][cur.y]) continue;
            mark[cur.x][cur.y] = true;
        }
        else{
            if(mark[cur.x][cur.y] || visited[cur.x][cur.y]) continue;
            visited[cur.x][cur.y] = true;

            if(cur.x == 1 || cur.x == n || cur.y == 1 || cur.y == m){
                cout << "YES\n";

                #define cerr if(false)cerr
                for(int i = 1; i <= n; ++i){
                    for(int j = 1; j <= m; ++j){
                        cerr << trace[i][j] << '\t';
                    }
                    cerr << '\n';
                }

                int x = cur.x, y = cur.y;
                vector<char> res;
                while(!(start.x == x && start.y == y)){
                    res.push_back(idx_to_dir(trace[x][y]));

                    int d = trace[x][y];
                    x = x - dx[d], y = y - dy[d];

                    cerr << x << ' ' << y << '\n';
                }

                reverse(begin(res), end(res));
                cout << (int)res.size() << '\n';
                for(char d: res) cout << d;

                return;
            }
        }

        for(int d = 0; d < 4; ++d){
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && arr[nx][ny] != '#' && !visited[nx][ny] && !mark[nx][ny]){
                if(cur.type == 'A'){
                    trace[nx][ny] = d;
                }
                que.push({nx, ny, cur.type});
            }
        }
    }

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i] = ' ' + arr[i];
    }

    bfs();

    return 0;
}
