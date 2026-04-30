/******************************************************************************
Link: https://codeforces.com/contest/2227/problem/D
Code: 2227D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-30-22.15.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int find_mex(vector<int>& a) {
    sort(a.begin(), a.end());

    int mex = 0;
    for(int x: a){
        if(x == mex) ++mex;
        else if(x > mex) break;
    }

    return mex;
}


void solve(){
    int n;
    cin >> n;

    vector<int> a(n * 2 + 1);
    vector<int> pos0;
    for(int i = 1; i <= n * 2; ++i){
        cin >> a[i];

        if(a[i] == 0)
            pos0.push_back(i);
    }

    int res = 0;
    {
        for(int p: pos0){
            int i = p, j = p;
            vector<int> S;
            while(1 <= i && j <= n * 2 && a[i] == a[j]){
                S.push_back(a[i]);
                --i; ++j;
            }

            res = max(res, find_mex(S));
        }
    }

    int u = pos0[0], v = pos0[1];

    int i1 = u, j1 = v;
    while(i1 <= j1 && a[i1] == a[j1]){
        ++i1; --j1;
    }
    if(i1 > j1){
        int i2 = u, j2 = v;
        while(1 <= i2 && j2 <= n * 2 && a[i2] == a[j2]){
            --i2; ++j2;
        }

        ++i2; --j2;

        vector<int> S(begin(a) + i2, begin(a) + j2 + 1);
        res = max(res, find_mex(S));
    }

    cout << res << "\n";
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
