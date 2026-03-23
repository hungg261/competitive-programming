#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    set<int> left;
    for(int i = 1; i <= n; ++i) left.insert(i);

    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        if(left.find(cur) != left.end()){
            cout << cur << ' ';
            left.erase(cur);
        }
        else{
            cout << (*left.begin()) << ' ';
            left.erase(left.begin());
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
