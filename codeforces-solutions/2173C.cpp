#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    set<int> S, cnt;
    for(int &ele: arr){
        cin >> ele;
        S.insert(ele);
        cnt.insert(ele);
    }

    vector<int> res;
    while(!S.empty()){
        int cur = *S.begin();
        res.push_back(cur);
        S.erase(S.begin());

        for(int m = cur; m <= k; m += cur){
            if(!cnt.count(m)){
                cout << "-1\n";
                return;
            }

            if(S.count(m)) S.erase(m);
        }
    }

    cout << res.size() << '\n';
    for(int ele: res) cout << ele << ' '; cout << '\n';
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
