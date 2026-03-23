/******************************************************************************
Link: https://codeforces.com/group/2W1wfqmLNZ/contest/675179/problem/A
Code: Group_2W1wfqmLNZ_675179A
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-13-14.40.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct FenwickTree2D{
    int n;
    vector<vector<int>> ys;
    vector<vector<int>> bit;

    FenwickTree2D(int n): n(n){
        ys.resize(n + 1);
        bit.resize(n + 1);
    }

    void fake_update(int x, int y){
        ++x; ++y;
        for(int i = x; i <= n; i += i & -i){
            ys[i].push_back(y);
        }
    }

    void build(){
        for(int i = 1; i <= n; ++i){
            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            bit[i].assign(ys[i].size() + 1, 0);
        }
    }

    void update(int x, int y, int v){
        ++x; ++y;

        for(int i = x; i <= n; i += i & -i){
            int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin() + 1;
            for(; j < (int)bit[i].size(); j += j & -j){
                bit[i][j] += v;
            }
        }
    }

    int query(int x, int y) const{
        ++x; ++y;

        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            int j = upper_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
            for(; j > 0; j -= j & -j){
                res += bit[i][j];
            }
        }
        return res;
    }

    int rect(int x1, int y1, int x2, int y2) const{
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

const int INF = 1e18;
const int MAXN = 1e5, MAXQ = 1e5;
int n, q;
pair<int, int> status[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("XEPHANG.INP","r",stdin);
    freopen("XEPHANG.OUT","w",stdout);

    cin >> n >> q;

    FenwickTree2D fwt(MAXQ + 5);
    fwt.fake_update(0, 0);

    vector<pair<int, int>> queries;
    for(int i = 1; i <= q; ++i){
        int T, P;
        cin >> T >> P;

        ++status[T].first;
        status[T].second += P;

        fwt.fake_update(status[T].first, status[T].second);
        queries.emplace_back(T, P);
    }

    fwt.build();
    memset(status, 0, sizeof status);

    fwt.update(0, 0, n);
    for(const pair<int, int>& qr: queries){
        int T, P;
        tie(T, P) = qr;

        fwt.update(status[T].first, status[T].second, -1);
        ++status[T].first;
        status[T].second += P;
        fwt.update(status[T].first, status[T].second, 1);

        int x, y; tie(x, y) = status[1];
        int H = fwt.rect(x + 1, -INF, MAXQ, INF) + fwt.rect(x, -INF, x, y - 1);

        cout << H + 1 << '\n';
    }

    return 0;
}
