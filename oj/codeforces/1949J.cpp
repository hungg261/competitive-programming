/******************************************************************************
Link: https://codeforces.com/problemset/problem/1949/J
Code: 1949J
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-23-15.22.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 50, INF = 1e9;
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

namespace Solve{

vector<pair<Point, Point>> ans;

Point furthest(const vector<Point> &source){
    queue<Point> que;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    pair<int, pair<int, int>> far = {-1, {-1, -1}};
    for(const Point &st: source){
        dist[st.x][st.y] = 0;
        far = max(far, {0, {st.x, st.y}});
        que.push(st);
    }

    while(!que.empty()){
        Point u = que.front(); que.pop();

        far = max(far, {dist[u.x][u.y], {u.x, u.y}});

        for(int d = 0; d < 4; ++d){
            Point v = {u.x + dx[d], u.y + dy[d]};
            if(v.inside() && S[v.x][v.y] == OCCUPIED && dist[v.x][v.y] == -1){
                que.push(v);
                dist[v.x][v.y] = dist[u.x][u.y] + 1;
            }
        }
    }

    int x, y; tie(x, y) = far.second;
    return Point(x, y);
}

// find the path that connects S-T
namespace Phase0{

vector<Point> path;
bool run(){
    queue<pair<Point, int>> que;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(S[i][j] == OCCUPIED){
                if(T[i][j] == OCCUPIED){
                    return true;
                }
                que.push({{i, j}, 0});
            }
        }
    }

    vector<vector<Point>> par(n, vector<Point>(m, Point()));
    vector<vector<int>> vis(n, vector<int>(m, false));
    while(!que.empty()){
        Point u; int mov;
        tie(u, mov) = que.front();
        que.pop();

        if(T[u.x][u.y] == OCCUPIED){
            while(u.exist()){
                path.push_back(u);
                u = par[u.x][u.y];
            }
            reverse(begin(path), end(path));
            return true;
        }

        if(vis[u.x][u.y]) continue;
        vis[u.x][u.y] = true;

        for(int d = 0; d < 4; ++d){
            Point v = {u.x + dx[d], u.y + dy[d]};
            if(v.inside() && S[v.x][v.y] == FREE && !vis[v.x][v.y]){
                que.push({v, mov + 1});
                if(!par[v.x][v.y].exist()) par[v.x][v.y] = u;
            }
        }
    }

    return false;
}

}

// move along the path S-T
namespace Phase1{

Point furthest(const Point &st){
    assert(st.inside() && S[st.x][st.y] == OCCUPIED);
    return Solve::furthest({st});
}

void run(){
    const vector<Point> &path = Phase0::path;
    int sz = path.size();
    for(int i = 1; i < sz; ++i){
        const Point &p = path[i];
        const Point &last = furthest(path[i - 1]);

        S[p.x][p.y] = OCCUPIED;
        S[last.x][last.y] = FREE;

        ans.emplace_back(last, p);
    }
}

}

// fill the rest of T
namespace Phase2{

void run(){
    int k = 0;
    vector<Point> L;
    vector<vector<int>> vis(n, vector<int>(m, false));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(T[i][j] == OCCUPIED){
                ++k;
                if(L.empty() && S[i][j] == OCCUPIED){
                    L.push_back({i, j});
                    vis[i][j] = true;
                }
            }
        }
    }

    while((int)L.size() < k){
        for(const Point &u: L){
            for(int d = 0; d < 4; ++d){
                Point v = {u.x + dx[d], u.y + dy[d]};
                if(v.inside() && T[v.x][v.y] == OCCUPIED){
                    if(S[v.x][v.y] == OCCUPIED){
                        if(vis[v.x][v.y]) continue;
                        L.push_back(v);
                        vis[v.x][v.y] = true;
                        goto passed;
                    }
                    else if(S[v.x][v.y] == FREE){
                        const Point &last = furthest(L);

                        S[v.x][v.y] = OCCUPIED;
                        S[last.x][last.y] = FREE;
                        ans.emplace_back(last, v);

                        goto passed;
                    }
                }
            }
        }

        passed:;
    }
}

}

void solve(){
    if(!Phase0::run()){
        cout << "NO\n";
        return;
    }

    Phase1::run();
    Phase2::run();

    cout << "YES\n";
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x.first << " " << x.second << endl;
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
