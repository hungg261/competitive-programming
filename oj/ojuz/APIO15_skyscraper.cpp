/******************************************************************************
Link: https://oj.uz/problem/view/APIO15_skyscraper
Code: APIO15_skyscraper
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-08-20.47.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e4, MAXM = 3e4, MAXSQRT = sqrt(MAXN) + 1;
struct Doge{
    int B, P;

    friend istream& operator >> (istream& is, Doge& dg){
        return is >> dg.B >> dg.P;
    }
};
vector<Doge> doges;
int N, M;


namespace Brute{

void solve(){
    vector<vector<pair<int, int>>> adj(N);
    for(int u = 0; u < M; ++u){
        int cur = doges[u].B;
        for(int f = cur, mv = 0; f < N;
                f += doges[u].P, ++mv){
            if(f == cur) continue;
            adj[cur].push_back({f, mv});
        }
        for(int f = cur,
                mv = 0; f >= 0;
                f -= doges[u].P, ++mv){
            if(f == cur) continue;
            adj[cur].push_back({f, mv});
        }
    }

//    for(int u = 0; u < N; ++u){
//        for(const pair<int, int>& e: adj[u]){
//            cerr << u << " " << e.first << " " << e.second << endl;
//        }
//    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N, INT_MAX / 2);
    pq.push({dist[doges[0].B] = 0, doges[0].B});

    while(!pq.empty()){
        int cost, u;
        tie(cost, u) = pq.top(); pq.pop();

        if(cost != dist[u]) continue;

        for(const pair<int, int>& e: adj[u]){
            int v, w; tie(v, w) = e;
            int newCost = cost + w;
            if(newCost < dist[v]){
                dist[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }

    cout << (dist[doges[1].B] == INT_MAX / 2 ? -1 : dist[doges[1].B]) << "\n";
}

}


namespace Solve{

int dist[MAXN + 5][MAXSQRT + 1];
vector<int> at[MAXN + 5];

struct State{
    int u, p, cost;

    bool operator < (const State& other) const {
        return cost > other.cost;
    }
};

void solve(){
    memset(dist, 0x3f, sizeof dist);
    const int INF = dist[0][0];

    priority_queue<State> pq;
    dist[doges[0].B][0] = 0;
    pq.push({doges[0].B, 0, 0});

    auto make_jump = [&pq](int u, int p, int cost){
        int newL = u - p, newR = u + p;
        int newCost = cost + 1;

        if(newL >= 0 && newCost < dist[newL][p]){
            dist[newL][p] = newCost;
            pq.push({newL, p, newCost});
        }
        if(newR < N && newCost < dist[newR][p]){
            dist[newR][p] = newCost;
            pq.push({newR, p, newCost});
        }
    };

    while(!pq.empty()){
        State cur = pq.top();
        pq.pop();

        if(cur.p < MAXSQRT && dist[cur.u][cur.p] != cur.cost)
            continue;

        if(cur.u == doges[1].B && cur.p == 0) break;

        if(cur.p == 0){
            for(int p: at[cur.u]){
                if(p < MAXSQRT){
                    make_jump(cur.u, p, cur.cost);
                }
                else{
                    for(int pos = cur.u, mov = 0;
                            pos < N;
                            pos += p, ++mov){
                        if(pos == cur.u) continue;

                        int newCost = cur.cost + mov;
                        if(newCost < dist[pos][0]){
                            dist[pos][0] = newCost;
                            pq.push({pos, 0, newCost});
                        }
                    }
                    for(int pos = cur.u, mov = 0;
                            pos >= 0;
                            pos -= p, ++mov){
                        if(pos == cur.u) continue;

                        int newCost = cur.cost + mov;
                        if(newCost < dist[pos][0]){
                            dist[pos][0] = newCost;
                            pq.push({pos, 0, newCost});
                        }
                    }
                }
            }
        }
        else{
            make_jump(cur.u, cur.p, cur.cost);
            if(cur.cost < dist[cur.u][0]){
                dist[cur.u][0] = cur.cost;
                pq.push({cur.u, 0, cur.cost});
            }
        }
    }

    int res = dist[doges[1].B][0];
    cout << (res == INF ? -1 : res) << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    doges.resize(M);
    for(int i = 0; i < M; ++i){
        cin >> doges[i];
        Solve::at[doges[i].B].push_back(doges[i].P);
    }

    for(int i = 0; i < M; ++i){
        sort(Solve::at[i].begin(), Solve::at[i].end());
        Solve::at[i].erase(unique(Solve::at[i].begin(), Solve::at[i].end()), Solve::at[i].end());
    }

    Solve::solve();

    return 0;
}
