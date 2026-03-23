#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    multiset<int, greater<int>> h;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        h.insert(cur);
    }

    while(m--){
        int t;
        cin >> t;

        auto it = h.lower_bound(t);
        if(it != h.end()){
            cout << *it << '\n';
            h.erase(it);
        }
        else cout << "-1\n";
    }

    return 0;
}
