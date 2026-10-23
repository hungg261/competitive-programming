/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_noiday
Code: nvnamson_noiday
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-10.13.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;

namespace Brute{

namespace StressTest{

vector<int> b;
map<pair<int,int>, int> memo;

// f(i, j) = thao tac it nhat cho [1..i] va phan tu cuoi <= j
int f(int i, int j){
    if(i == 0) return 0;
    auto it = memo.find({i, j});
    if(it != memo.end()) return it->second;

    int v = b[i];
    int best = INT_MAX;

    if(v <= j){
        int sub = f(i - 1, v);
        if(sub < best) best = sub;
    }

    for(int m = 1; m < v; ++m){
        int kmax = v / m;
        int kmin = 1 + (v - m + j - 1) / j;
        if(kmin > kmax) continue;

        int sub = f(i - 1, m);
        if(sub == INT_MAX) continue;

        int cur = (kmin - 1) + sub;
        if(cur < best) best = cur;
    }

    memo[{i, j}] = best;
    return best;
}

int subsolve(int l, int r, const vector<int> &a){
    int m = r - l + 1;
    b.assign(m + 1, 0);
    for(int i = 1; i <= m; ++i){
        b[i] = a[l + i - 1];
    }
    memo.clear();
    int ans = f(m, b[m]);
    return ans == INT_MAX ? -1 : ans;
}

}

int subsolve(int l, int r, const vector<int> &a){
    int res = 0, bound = a[r];
    for(int i = r - 1; i >= l; --i){
        int p = (a[i] + bound - 1) / bound;
        res = (res + p - 1) % MOD;
        bound = a[i] / p;
    }

    return res;
}

void solve(const vector<int> &a, int n){
    int res = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            res = (res + subsolve(i, j, a)) % MOD;
        }
    }

    cout << res << "\n";
}

}

namespace Subtask1{ // t <= 1e4 :vv

void solve(const vector<int> &a, int n){
    int res = 0;
    for(int r = 1; r <= n; ++r){
        int bound = a[r];
        int cur = 0;
        for(int l = r - 1; l >= 1; --l){
            int p = (a[l] + bound - 1) / bound;
            cur = (cur + p - 1) % MOD;
            bound = a[l] / p;
            res = (res + cur) % MOD;
        }
    }
    cout << res << "\n";
}

}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    Subtask1::solve(a, n);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
