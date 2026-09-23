/******************************************************************************
Link: https://oj.uz/problem/view/JOI18_bitaro
Code: JOI18_bitaro
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-23-20.35.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5, MAXQ = 1e5, MAXSQRT = 200;
int n, m, q;
vector<int> adj[MAXN + 5], rev_adj[MAXN + 5];

struct Query{
    int T; vector<int> Y;
    int size() const { return Y.size(); }

    void mark(vector<int>& marker, int target = true){
        for(int u: Y)
            marker[u] = target;
    }

} Q[MAXQ + 5];

namespace Solve{

struct Node{
    int u, cost;

    bool operator < (const Node& other) const {
        return cost < other.cost;
    }
    bool operator > (const Node& other) const {
        return cost > other.cost;
    }
};
vector<Node> best[MAXN + 5];

void compute(){
    vector<int> chosen(n + 1, false);
    for(int u = 1; u <= n; ++u){
        vector<Node>& cand = best[u];
        cand.push_back({u, 0});

        for(int v: rev_adj[u]){
            sort(begin(best[v]), end(best[v]), greater<Node>());
            vector<Node> temp;

            int sz_i = cand.size(), sz_j = best[v].size();
            int i = 0, j = 0;
            while(i < sz_i && j < sz_j){
                while(i < sz_i && chosen[cand[i].u]) ++i;
                while(j < sz_j && chosen[best[v][j].u]) ++j;

                if(i >= sz_i || j >= sz_j) break;

                const Node new_node{best[v][j].u, best[v][j].cost + 1};
                if(cand[i] > new_node){
                    chosen[cand[i].u] = true;
                    temp.push_back(cand[i++]);
                }
                else{
                    chosen[new_node.u] = true;
                    temp.push_back(new_node);
                    j++;
                }

                if((int)temp.size() >= MAXSQRT) break;
            }

            while(i < sz_i && (int)temp.size() < MAXSQRT){
                if(!chosen[cand[i].u]) temp.push_back(cand[i]);
                i++;
            }
            while(j < sz_j && (int)temp.size() < MAXSQRT){
                if(!chosen[best[v][j].u]){
                    const Node new_node{best[v][j].u, best[v][j].cost + 1};
                    temp.push_back(new_node);
                }
                j++;
            }

            cand = move(temp);
            for(const Node& node: cand)
                chosen[node.u] = false;
        }
    }
}

void solve(){
    compute();

    vector<int> mark(n + 1, false);
    vector<int> passed(n + 1);
    vector<vector<Node>> memo(n + 1);

    auto getMax = [&mark](const vector<Node>& B) -> int {
        int res = -1;
        for(const Node& e: B){
            if(!mark[e.u]) res = max(res, e.cost);
        }
        return res;
    };

    for(int qr = 1; qr <= q; ++qr){
        int T = Q[qr].T;
        Q[qr].mark(mark, true);

        int sz = Q[qr].size();
        if(sz < MAXSQRT){
            cout << getMax(best[T]) << "\n";
        }
        else{
            if(!passed[T]){
                vector<int> dp(n + 1, INT_MIN);
                dp[T] = 0;

                for(int u = n; u >= 1; --u){
                    for(int v: rev_adj[u]){
                        dp[v] = max(dp[v], dp[u] + 1);
                    }

                    if(dp[u] >= 0) memo[T].push_back({u, dp[u]});
                }

                passed[T] = true;
            }
            cout << getMax(memo[T]) << "\n";
        }
        Q[qr].mark(mark, false);
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 1; i <= q; ++i){
        int k;
        cin >> Q[i].T >> k;

        Q[i].Y.resize(k);
        for(int j = 0; j < k; ++j)
            cin >> Q[i].Y[j];
    }

    Solve::solve();

    return 0;
}
