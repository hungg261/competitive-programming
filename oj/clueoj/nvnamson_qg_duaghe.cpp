/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_qg_duaghe
Code: nvnamson_qg_duaghe
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-03-20.59.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

int N;
vector<int> deg;
vector<vector<pair<int,int>>> adj;
bool all_eq = true;

namespace Subtask1{

void solve(){
    int ans = 0;
    vector<bool> vis(N);
    vector<int> sum(N);
    vector<int> mx(N);

    for(int u = 0; u < N; ++u){
        fill(begin(vis), end(vis), false);
        fill(begin(sum), end(sum), 0);
        fill(begin(mx), end(mx), 0);

        queue<int> q;
        q.push(u);
        vis[u] = true;

        while(!q.empty()){
            int c = q.front();
            q.pop();

            for(auto& p: adj[c]){
                int v, w;
                tie(v, w) = p;

                if(!vis[v]){
                    vis[v] = true;
                    sum[v] = sum[c] + w;
                    mx[v] = max(mx[c], w);
                    q.push(v);
                }
            }
        }

        for(int v = u + 1; v < N; ++v){
            if(2 * mx[v] < sum[v]) ++ans;
        }
    }

    cout << ans << "\n";
}

}

namespace Subtask2{

void solve(){
    if(N <= 2){
        cout << 0 << "\n";
        return;
    }

    int total = N * (N - 1) / 2;
    int non_bal = N - 1;

    for(int i = 0; i < N; ++i){
        non_bal += deg[i] * (deg[i] - 1) / 2;
    }

    cout << total - non_bal << "\n";
}

}

namespace Subtask3{

vector<int> W;

int dnc(int lo, int hi){
    if(hi - lo < 3) return 0;

    int mid = (lo + hi) / 2;
    int res = dnc(lo, mid) + dnc(mid, hi);

    int nL = mid - lo, nR = hi - mid;

    vector<int> SL(nL), ML(nL), SR(nR), MR(nR);

    SL[nL - 1] = W[mid - 1];
    ML[nL - 1] = W[mid - 1];
    for(int t = nL - 2; t >= 0; --t){
        SL[t] = SL[t + 1] + W[lo + t];
        ML[t] = max(ML[t + 1], W[lo + t]);
    }

    SR[0] = W[mid];
    MR[0] = W[mid];
    for(int t = 1; t < nR; ++t){
        SR[t] = SR[t - 1] + W[mid + t];
        MR[t] = max(MR[t - 1], W[mid + t]);
    }

    {
        vector<int> comp(SR);
        sort(begin(comp), end(comp));
        comp.erase(unique(begin(comp), end(comp)), end(comp));

        FenwickTree bit(comp.size());

        int ptr = 0;
        for(int t1 = nL - 1; t1 >= 0; --t1){
            while(ptr < nR && MR[ptr] <= ML[t1]){
                int pos = lower_bound(begin(comp), end(comp), SR[ptr]) - begin(comp) + 1;
                bit.update(pos, 1);
                ++ptr;
            }

            int threshold = 2 * ML[t1] - SL[t1];
            int idx = upper_bound(begin(comp), end(comp), threshold) - begin(comp);

            res += bit.get(idx + 1, comp.size());
        }
    }

    {
        vector<int> comp(SL);
        sort(begin(comp), end(comp));
        comp.erase(unique(begin(comp), end(comp)), end(comp));

        FenwickTree bit(comp.size());

        int ptr = nL - 1;
        for(int t2 = 0; t2 < nR; ++t2){
            while(ptr >= 0 && ML[ptr] < MR[t2]){
                int pos = lower_bound(begin(comp), end(comp), SL[ptr]) - begin(comp) + 1;
                bit.update(pos, 1);
                --ptr;
            }

            int threshold = 2 * MR[t2] - SR[t2];
            int idx = upper_bound(begin(comp), end(comp), threshold) - begin(comp);

            res += bit.get(idx + 1, comp.size());
        }
    }

    return res;
}

void solve(){
    W.clear();

    int start = -1;
    for(int i = 0; i < N; ++i){
        if(deg[i] == 1){
            start = i;
            break;
        }
    }

    int cur = start, prev = -1;
    for(int step = 0; step < N - 1; ++step){
        for(auto& p: adj[cur]){
            int v, w;
            tie(v, w) = p;

            if(v != prev){
                W.push_back(w);
                prev = cur;
                cur = v;
                break;
            }
        }
    }

    cout << dnc(0, N - 1) << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    deg.assign(N, 0);
    adj.assign(N, {});

    int first_w = -1;
    for(int i = 0; i < N - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;

        ++deg[u];
        ++deg[v];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        if(first_w == -1) first_w = w;
        else if(w != first_w) all_eq = false;
    }

    bool is_path = true;
    for(int i = 0; i < N; ++i){
        if(deg[i] > 2){
            is_path = false;
            break;
        }
    }

    if(all_eq) Subtask2::solve();
    else if(is_path) Subtask3::solve();
    else Subtask1::solve();

    return 0;
}

