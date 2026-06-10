/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_anhdep
Code: hsg_hcm_v2_25_anhdep
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-18-14.55.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct SparseFenwickTree2D{
    int n;
    vector<vector<int>> Ys;
    vector<vector<int>> BIT;

    SparseFenwickTree2D(int _n): n(_n){
        Ys.resize(n + 2);
        BIT.resize(n + 2);
    }

    void fake_update(int x, int y){
        ++x; ++y;
        for(int i = x; i <= n; i += i & -i){
            Ys[i].push_back(y);
        }
    }

    void build(){
        for(int x = 1; x <= n; ++x){
            sort(begin(Ys[x]), end(Ys[x]));
            Ys[x].erase(unique(begin(Ys[x]), end(Ys[x])), end(Ys[x]));
            BIT[x].resize(Ys[x].size() + 1, 0);
        }
    }

    void update(int x, int y, int val = 1){
        ++x; ++y;

        for(int i = x; i <= n; i += i & -i){
            int j = lower_bound(begin(Ys[i]), end(Ys[i]), y) - begin(Ys[i]) + 1;
            for(; j < (int)BIT[i].size(); j += j & -j){
                BIT[i][j] += val;
            }
        }
    }

    int get(int x, int y){
        ++x; ++y;

        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            int j = upper_bound(begin(Ys[i]), end(Ys[i]), y) - begin(Ys[i]);
            for(; j > 0; j -= j & -j){
                res += BIT[i][j];
            }
        }
        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        if(x1 > x2 || y1 > y2) return 0;
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

const int MAXN = 1e5, MAXQ = 1e5;
const int INF = 1e9;
vector<int> values;
struct Picture{
    int S, T;
    int sum;

    bool operator > (const Picture& other) const {
        return sum > other.sum;
    }
};

struct Judge{
    int X, Y, Z;
    int id;
};

struct Point{
    int X, Y, id;
};

int N, Q;
Picture pictures[MAXN + 5];
Judge judges[MAXQ + 5];
vector<vector<Point>> queries;

void solve(){
    int sz = queries.size();
    SparseFenwickTree2D fwt(sz + 3);
    sort(pictures + 1, pictures + N + 1, greater<Picture>());
    for(int i = 1; i <= N; ++i) fwt.fake_update(pictures[i].S, pictures[i].T);
    fwt.build();

    int ptr = 1;
    vector<int> res(Q + 1, -1);
    for(int i = sz - 1; i >= 0; --i){
        for(; ptr <= N && pictures[ptr].sum >= i; ++ptr)
            fwt.update(pictures[ptr].S, pictures[ptr].T);

        for(const Point& p: queries[i]){
            res[p.id] = fwt.get(p.X, p.Y, sz, sz);
        }
    }

    for(int i = 1; i <= Q; ++i){
        cout << res[i] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ANHDEP.INP","r",stdin);
    freopen("ANHDEP.OUT","w",stdout);

    cin >> N >> Q;

    for(int i = 1; i <= N; ++i){
        int S, T; cin >> S >> T;

        pictures[i] = {S, T, S + T};
        values.push_back(S);
        values.push_back(T);
        values.push_back(S + T);
    }
    for(int i = 1; i <= Q; ++i){
        int X, Y, Z; cin >> X >> Y >> Z;

        judges[i] = {X, Y, Z, i};
        values.push_back(X);
        values.push_back(Y);
        values.push_back(Z);
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));
    queries.resize(values.size() + 1);

    auto f = [&](int x){ return lower_bound(begin(values), end(values), x) - begin(values); };

    for(int i = 1; i <= N; ++i){
        pictures[i].S = f(pictures[i].S);
        pictures[i].T = f(pictures[i].T);
        pictures[i].sum = f(pictures[i].sum);
    }
    for(int i = 1; i <= Q; ++i){
        judges[i].X = f(judges[i].X);
        judges[i].Y = f(judges[i].Y);
        judges[i].Z = f(judges[i].Z);

        queries[judges[i].Z].push_back({judges[i].X, judges[i].Y, judges[i].id});
    }

    solve();

    return 0;
}
