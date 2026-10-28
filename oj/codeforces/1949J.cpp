/******************************************************************************
Link: https://codeforces.com/problemset/problem/1949/J
Code: 1949J
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-08.45.32
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;
const char FREE = '.', OCCUPIED = '*', BLOCKED = 'X';
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m;
struct Point{
    int x, y;
    Point(int _x = -1, int _y = -1): x(_x), y(_y){}

    bool exist(){ return x != -1 && y != -1; }

    bool inside() const { return 0 <= x && x < n && 0 <= y && y < m; }
    bool operator == (const Point &other) const { return x == other.x && y == other.y; }

    friend ostream &operator << (ostream &os, const Point &p){
        return os << p.x + 1 << " " << p.y + 1;
    }
};

string S[MAX], T[MAX];


namespace GetComponent{ vector<Point> bfs(Point origin, string grid[]); }
namespace FindPath{ vector<Point> bfs(Point s, const Point &t, string grid[]); }
namespace Connected{ bool check(string grid[]); }


namespace Solve{

void solve(){
    auto pick = [&](string grid[]) -> Point {
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == OCCUPIED){
                    return {i, j};
                }
            }
        }
        abort();
    };

    auto getQueue = [&](Point origin, string grid[]) -> queue<Point> {
        queue<Point> que;
        for(const Point &p: GetComponent::bfs(origin, grid)){
            que.push(p);
        }
        return que;
    };

    Point pointS = pick(S), pointT = pick(T);

    vector<Point> stateS = GetComponent::bfs(pointS, S);
    vector<Point> stateT = GetComponent::bfs(pointT, T);
    queue<Point> queueT = getQueue(pointT, T);
    vector<Point> path = FindPath::bfs(pointS, pointT, T);

    if(path.empty()){
        cout << "NO\n";
        return;
    }

    vector<pair<Point, Point>> res;

    for(const Point &p: path){
//        cerr << p << endl;
        if(S[p.x][p.y] == OCCUPIED) continue;
//        if(T[p.x][p.y] == OCCUPIED) continue;

        Point removeS;
        for(const Point &pt: stateS){
            if(pt == p) continue;
            if(T[pt.x][pt.y] == OCCUPIED) continue;
            S[pt.x][pt.y] = FREE;
            if(Connected::check(S)){
                S[p.x][p.y] = OCCUPIED;
                if(Connected::check(S)){ removeS = pt; break; }
                S[p.x][p.y] = FREE;
            }
            S[pt.x][pt.y] = OCCUPIED;
        }
        if(!removeS.exist()){
            for(const Point &pt: stateS){
                if(pt == p) continue;
                if(T[pt.x][pt.y] != OCCUPIED) continue;
                S[pt.x][pt.y] = FREE;
                if(Connected::check(S)){
                    S[p.x][p.y] = OCCUPIED;
                    if(Connected::check(S)){ removeS = pt; break; }
                    S[p.x][p.y] = FREE;
                }
                S[pt.x][pt.y] = OCCUPIED;
            }
        }


        if(removeS.exist()){
            S[p.x][p.y] = OCCUPIED;
            stateS.erase(find(begin(stateS), end(stateS), removeS));
            stateS.push_back(p);
            res.push_back({removeS, p});
        }
    }


    while(!queueT.empty()){
        const Point p = queueT.front(); queueT.pop();
//        cerr << "running: " << p << endl;
        if(S[p.x][p.y] == OCCUPIED) continue;

        Point removeS;
        for(const Point &pt: stateS){
            if(pt == p) continue;
            if(T[pt.x][pt.y] == OCCUPIED) continue;
            S[pt.x][pt.y] = FREE;
            if(Connected::check(S)){
                S[p.x][p.y] = OCCUPIED;
                if(Connected::check(S)){ removeS = pt; break; }
                S[p.x][p.y] = FREE;
            }
            S[pt.x][pt.y] = OCCUPIED;
        }
        if(!removeS.exist()){
            for(const Point &pt: stateS){
                if(pt == p) continue;
                if(T[pt.x][pt.y] != OCCUPIED) continue;
                S[pt.x][pt.y] = FREE;
                if(Connected::check(S)){
                    S[p.x][p.y] = OCCUPIED;
                    if(Connected::check(S)){ removeS = pt; break; }
                    S[p.x][p.y] = FREE;
                }
                S[pt.x][pt.y] = OCCUPIED;
            }
        }

        if(removeS.exist()){
            S[p.x][p.y] = OCCUPIED;
            stateS.erase(find(begin(stateS), end(stateS), removeS));
            stateS.push_back(p);
            res.push_back({removeS, p});
        }
        else abort();

        if(T[removeS.x][removeS.y] == OCCUPIED){
            queueT.push(removeS);
        }
    }

    cout << "YES\n";
    cout << (int)res.size() << "\n";
    for(const pair<Point, Point> &e: res){
        cout << e.first << " " << e.second << "\n";
    }
}

}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> S[i];
    for(int i = 0; i < n; ++i) cin >> T[i];

    Solve::solve();

    return 0;
}


namespace GetComponent{

vector<Point> bfs(Point origin, string grid[]){
    vector<Point> coords;
    queue<Point> que;
    que.push(origin);

    vector<vector<int>> vis(n, vector<int>(m, false));

    while(!que.empty()){
        Point cur = que.front();
        que.pop();

        if(vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y] = true;
        coords.push_back(cur);

        for(int d = 0; d < 4; ++d){
            Point nxt = {cur.x + dx[d], cur.y + dy[d]};
            if(nxt.inside() && !vis[nxt.x][nxt.y] && grid[nxt.x][nxt.y] == OCCUPIED){
                que.push(nxt);
            }
        }
    }

    return coords;
}

}


namespace FindPath{

vector<Point> bfs(Point s, const Point &t, string grid[]){
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<Point>> par(n, vector<Point>(m, {-1, -1}));
    queue<Point> q;

    vis[s.x][s.y] = true;
    q.push(s);

    while(!q.empty()){
        Point u = q.front(); q.pop();
        if(u == t) break;
        for(int d = 0; d < 4; ++d){
            Point v = {u.x + dx[d], u.y + dy[d]};
            if(v.inside() && !vis[v.x][v.y] && grid[v.x][v.y] != BLOCKED){
                vis[v.x][v.y] = true;
                par[v.x][v.y] = u;
                q.push(v);
            }
        }
    }

    vector<Point> coords;
    if(!vis[t.x][t.y]) return coords;

    for(Point cur = t; ; cur = par[cur.x][cur.y]){
        coords.push_back(cur);
        if(cur == s) break;
    }
    reverse(coords.begin(), coords.end());

    return coords;
}

}

namespace Connected{

bool check(string grid[]){
    vector<vector<int>> vis(n, vector<int>(m, false));
    function<void(Point)> dfs = [&](Point u){
        vis[u.x][u.y] = true;
        for(int d = 0; d < 4; ++d){
            Point v = {u.x + dx[d], u.y + dy[d]};
            if(v.inside() && !vis[v.x][v.y] && grid[v.x][v.y] == OCCUPIED){
                dfs(v);
            }
        }
    };

    int cc = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!vis[i][j] && grid[i][j] == OCCUPIED){
                dfs({i, j});
                ++cc;
            }

            if(cc > 1) return false;
        }
    }
    return true;
}

}
