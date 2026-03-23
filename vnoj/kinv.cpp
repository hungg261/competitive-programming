/******************************************************************************
Link: https://vjudge.net/contest/732386#problem/J
Code: J
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-06-11.24.41
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9;
struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz): n(sz){
        BIT.resize(sz + 1, 0);
    }

    void update(int idx, int val){
        for(int i = idx; i <= n; i += i & -i) BIT[i] = (BIT[i] + val) % MOD;
    }

    int get(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= i & -i) res = (res + BIT[i]) % MOD;
        return res;
    }

    int get(int l, int r){ return ((get(r) - get(l - 1)) % MOD + MOD) % MOD; }
};

struct Element{
    int value, idx;

    operator int() const{ return value; }
    &operator int(){ return value; }
};

const int MAXN = 10000, MAXK = 10;
int n, k, dp[MAXN + 5][MAXK + 5];
Element arr[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("J.INP","r",stdin);
    //freopen("J.OUT","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i].idx = i;
    }
    sort(arr + 1, arr + n + 1, [](auto& x, auto& y){
            return x > y || (x == y && x.idx > y.idx);
         });

    vector<FenwickTree> dp(k + 1, FenwickTree(n));
    for(int i = 1; i <= n; ++i){
        dp[1].update(arr[i].idx, 1);
        for(int len = 2; len <= k; ++len){
            int cur = dp[len - 1].get(arr[i].idx - 1);
            dp[len].update(arr[i].idx, cur);
        }
    }

    int ans = dp[k].get(n);
    cout << ans << '\n';

    return 0;
}
