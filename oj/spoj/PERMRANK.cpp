/******************************************************************************
Link: https://www.spoj.com/problems/PERMRANK
Code: PERMRANK
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-22.34.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 20;
int fact[MAXN + 5];

void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i)
        fact[i] = fact[i - 1] * i;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> s = a;
    sort(begin(s), end(s));

    int res = 0;
    vector<int> used(n, false);
    for(int pos = 0; pos < n; ++pos){
        int idx = lower_bound(begin(s), end(s), a[pos]) - begin(s);
        for(int i = 0; i < idx; ++i){
            if(!used[i]) res += fact[n - pos - 1];
        }
        used[idx] = true;
    }

    cout << res + 1 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    compute();

    while(t--){
        solve();
    }

    return 0;
}
