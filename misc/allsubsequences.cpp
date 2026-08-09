#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e5;
const int MOD = 998244353;

struct FenwickTree{
    int n;
    vector<int> bit;

    FenwickTree(int _n): n(_n){
        bit.resize(n + 1, 0);
    }

    void update(int pos, int val){
        val %= MOD;
        for(int i = pos; i <= n; i += i & -i){
            bit[i] += val;
            bit[i] %= MOD;
        }
    }

    int getTo(int x){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            res += bit[i];
            res %= MOD;
        }
        return res;
    }
    int getFr(int x){ return getTo(n) - getTo(x - 1); }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    vector<int> values = {0};
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }
    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    auto v = [&](int x){
        return lower_bound(begin(values), end(values), x) - begin(values) + 1;
    };


    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    FenwickTree fwt1(values.size()), fwt2(values.size()), fwt3(values.size()), fwt4(values.size());

    int res = 0;
    for(int i = 1; i <= n; ++i){
        dp[i] += a[i] * fwt1.getTo(v(a[i])) % MOD - fwt2.getTo(v(a[i])) + a[i] * fwt3.getTo(v(a[i])) % MOD - fwt4.getTo(v(a[i]));
        dp[i] = (dp[i] % MOD + MOD) % MOD;
        dp[i] += - a[i] * fwt1.getFr(v(a[i])) % MOD + fwt2.getFr(v(a[i])) - a[i] * fwt3.getFr(v(a[i])) % MOD + fwt4.getFr(v(a[i]));
        dp[i] = (dp[i] % MOD + MOD) % MOD;

        fwt1.update(v(a[i]), 1);
        fwt2.update(v(a[i]), a[i]);
        fwt3.update(v(a[i]), dp[i]);
        fwt4.update(v(a[i]), a[i] * dp[i]);

        res += dp[i];
        res %= MOD;
    }

    cout << (res % MOD + MOD) % MOD << "\n";

    return 0;
}

/*
10
13 5 1 30 73 16 5 1 30 59
*/
