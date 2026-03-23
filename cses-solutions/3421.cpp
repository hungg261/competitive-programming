#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    int ans = 1;
    map<int, int> mark;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        ++mark[cur];
    }

    for(const auto& p: mark){
        ans = (1LL * ans * (p.second + 1)) % MOD;
    }

    cout << (ans - 1 + MOD) % MOD << '\n';

    return 0;
}
