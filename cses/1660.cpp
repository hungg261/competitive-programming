#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    unordered_map<long long, int> mark;
    ++mark[0];

    long long prefix = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        prefix += cur;

        if(mark.count(prefix - x)) ans += mark[prefix - x];

        ++mark[prefix];
    }

    cout << ans << '\n';

    return 0;
}
