#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> mark(n, 0);
    long long prefix = 0; ++mark[prefix];

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        prefix += cur;
        ++mark[(prefix % n + n) % n];
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans += 1LL * mark[i] * (mark[i] - 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}
