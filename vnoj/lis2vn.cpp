/******************************************************************************
Link: https://vjudge.net/contest/732386#problem/K
Code: K
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-06-18.32.39
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree2D{
    vector<vector<int>> nodes;
    vector<vector<int>> BIT;
    int n, m;

    FenwickTree2D() = default;
    FenwickTree2D(int _n, int _m): n(_n), m(_m){ nodes.resize(_n + 1); BIT.resize(_n + 1); }

    void fakeUpdate(int x, int y){
        for(int i = x; i <= n; i += i & -i) nodes[i].push_back(y);
    }

    void fakeQuery(int x, int y){
        for(int i = x; i > 0; i -= i & -i) nodes[i].push_back(y);
    }

    void compress(){
        for(int i = 1; i <= n; ++i){
            nodes[i].push_back(0);
            sort(begin(nodes[i]), end(nodes[i]));
            nodes[i].erase(unique(begin(nodes[i]), end(nodes[i])), end(nodes[i]));

            BIT[i].resize((int) nodes[i].size() + 1, 0);
        }
    }

    void update(int x, int y, int val){
        for(int i = x; i <= n; i += i & -i){
            int j = lower_bound(begin(nodes[i]), end(nodes[i]), y) - begin(nodes[i]) + 1;
            for(; j <= (int)nodes[i].size(); j += j & -j){
                BIT[i][j] = max(BIT[i][j], val);
            }
        }
    }

    int get(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            int j = lower_bound(begin(nodes[i]), end(nodes[i]), y) - begin(nodes[i]) + 1;
            for(; j > 0; j -= j & -j){
                res = max(res, BIT[i][j]);
            }
        }

        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

struct Element{
    int first, second;
    int idx;

    bool operator < (const Element& other){
        return (this->first < other.first) || (this->first == other.first && this->second > other.second) ||
            ((this->first == other.first && this->second == other.second) && this->idx > other.idx);
    }
};

const int MAXVAL = 2e9 + 5, OFFSET = 1e9 + 1;
const int MAXN = 2e5;
Element arr[MAXN + 5];
int n;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("K.INP","r",stdin);
    //freopen("K.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].first >> arr[i].second;

        arr[i].first += OFFSET;
        arr[i].second += OFFSET;
        arr[i].idx = i;
    }
    sort(arr + 1, arr + n + 1);

    FenwickTree2D fwt(n, MAXVAL);
    for(int i = 1; i <= n; ++i){
        fwt.fakeQuery(arr[i].idx - 1, arr[i].second - 1);
        fwt.fakeUpdate(arr[i].idx, arr[i].second);
    }

    fwt.compress();

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int cur = fwt.get(arr[i].idx - 1, arr[i].second - 1) + 1;
        fwt.update(arr[i].idx, arr[i].second, cur);

        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
