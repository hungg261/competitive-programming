/******************************************************************************
Link: https://codeforces.com/contest/2053/problem/D
Code: 2053D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-07-15.57.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int powmod(int a, int b, int m){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, q;
    cin >> n >> q;

    array<vector<int>, 2> arr;
    array<vector<int>, 2> pos, rev;

    vector<pair<int, int>> temp(n + 1);
    for(int r = 0; r < 2; ++r){
        for(int i = 1; i <= n; ++i){
            int cur; cin >> cur;
            temp[i] = {cur, i};
        }
        sort(begin(temp) + 1, end(temp));

        arr[r].resize(n + 1);
        pos[r].resize(n + 1); rev[r].resize(n + 1);
        for(int i = 1; i <= n; ++i){
            const pair<int, int>& p = temp[i];
            arr[r][i] = p.first;

            pos[r][p.second] = i;
            rev[r][i] = p.second;
        }
    }

    //////////////////

    int res = 1;
    for(int i = 1; i <= n; ++i){
        res = res * min(arr[0][i], arr[1][i]) % MOD;
    }

    cout << res << ' ';

    while(q--){
        int o, x;
        cin >> o >> x;
        --o;

        int idx = pos[o][x];
        int nxt = -1;
        {
            int l = idx + 1, r = n;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(arr[o][mid] == arr[o][idx]){
                    nxt = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }

        if(nxt != -1){
            swap(pos[o][rev[o][idx]], pos[o][rev[o][nxt]]);
            swap(rev[o][idx], rev[o][nxt]);
            idx = nxt;
        }

        int old = min(arr[0][idx], arr[1][idx]);
        ++arr[o][idx];
        int nw = min(arr[0][idx], arr[1][idx]);

        res = res * powmod(old, MOD - 2, MOD) % MOD;
        res = res * nw % MOD;

        cout << res << ' ';
    }

    cout << '\n';
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
