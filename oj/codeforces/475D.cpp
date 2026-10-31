/******************************************************************************
Link: https://codeforces.com/contest/475/problem/D
Code: 475D
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-09.56.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<pair<int, int>> v;
    map<int, int> res;
    for(int i = 1; i <= n; ++i){
        vector<pair<int, int>> u = {{a[i], 1}};
        for(const pair<int, int> &p: v){
            int val, cnt; tie(val, cnt) = p;
            int g = __gcd(val, a[i]);

            if(g == u.back().first){
                u.back().second += cnt;
            }
            else{
                u.push_back({g, cnt});
            }
        }

        v = u;
        for(const pair<int, int> &p: v){
            res[p.first] += p.second;
        }
    }


    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;

        cout << res[x] << "\n";
    }

    return 0;
}
