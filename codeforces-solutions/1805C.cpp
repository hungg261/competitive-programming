/******************************************************************************
Link: https://codeforces.com/problemset/problem/1805/C
Code: 1805C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-14-21.41.12
*******************************************************************************/
#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> ks(n);
    vector<tuple<int, int, int>> parabolas(m);
    for(int i = 0; i < n; ++i) cin >> ks[i];
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        parabolas[i] = {a, b, c};
    }

    sort(begin(ks), end(ks));
    auto pow2 = [](int x){ return x * x; };

    for(int i = 0; i < m; ++i){
        int a, b, c;
        tie(a, b, c) = parabolas[i];

        int Lvalue = floor(b - 2 * sqrt(a * c)) + 1, Rvalue = ceil(b + 2 * sqrt(a * c)) - 1;
        int low = lower_bound(begin(ks), end(ks), Lvalue) - begin(ks),
            high = upper_bound(begin(ks), end(ks), Rvalue) - begin(ks) - 1;

        if(low > 0 && pow2(b - ks[low - 1]) < 4 * a * c) --low;
        if(high < n - 1 && pow2(b - ks[high + 1]) < 4 * a * c) ++high;

        if(low > high) cout << "NO\n";
        else{
            cout << "YES\n";
            cout << ks[low] << '\n';
        }
    }
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
