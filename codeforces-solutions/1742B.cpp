#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        set<int> s;
        for(int i = 0; i < n; ++i){
            int cur; cin >> cur;
            s.insert(cur);
        }

        cout << (s.size() == n ? "YES\n" : "NO\n");
    }

    return 0;
}
