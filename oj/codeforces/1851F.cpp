/******************************************************************************
Link: https://codeforces.com/problemset/problem/1851/F
Code: 1851F
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-07-14.01.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int arr[MAXN + 5], n, k;

pair<int, int> f(int a, int b){
    int res = 0, x = 0;
    for(int bit = k - 1; bit >= 0; --bit){
        int ba = (a >> bit & 1), bb = (b >> bit & 1);
        if(ba == bb){
            res |= 1 << bit;

            if(ba == 0) x |= 1 << bit;
        }
    }
    return {res, x};
}

array<int, 3> dfs(int b, vector<int> cand){
    if(b < 0){
        if((int)cand.size() < 2) return {0, 1, 2};
        else return {f(arr[cand[0]], arr[cand[1]]).first, cand[0], cand[1]};
    }

    int sz = cand.size();
    if(sz == 0) return {0, 1, 2};
    else if(sz == 1) return {0, 1, 2};
    else if(sz == 2) return {f(arr[cand[0]], arr[cand[1]]).first, cand[0], cand[1]};

    vector<int> B0, B1;
    for(int x: cand){
        if(arr[x] >> b & 1) B1.push_back(x);
        else B0.push_back(x);
    }

    return max(dfs(b - 1, B0), dfs(b - 1, B1));
}

void solve(){
    cin >> n >> k;

    vector<int> cand;
    for(int i = 1; i <= n; ++i){
        cand.push_back(i);

        cin >> arr[i];
    }

    array<int, 3> res = dfs(k - 1, cand);
    cout << res[1] << " " << res[2] << " " << f(arr[res[1]], arr[res[2]]).second << "\n";
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
