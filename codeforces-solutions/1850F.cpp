#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> freq;
    for(int& ele: arr){
        cin >> ele;
        ++freq[ele];
    }

    vector<int> cnt(n + 1, 0);
    int offset = 0;
    for(const pair<int, int>& p: freq){
        if(p.first == 1) offset += p.second;
        else for(int j = p.first; j <= n; j += p.first){
            cnt[j] += p.second;
        }
    }

    cout << *max_element(begin(cnt), end(cnt)) + offset << '\n';
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
