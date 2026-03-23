#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    vector<int> values;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        values.push_back(b[i]);
    }
    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    vector<vector<int>> events(n * 2);
    for(int i = 0; i < n; ++i){
        a[i] = lower_bound(begin(values), end(values), a[i]) - begin(values);
        b[i] = lower_bound(begin(values), end(values), b[i]) - begin(values);

        events[a[i]].push_back(0);
        events[b[i]].push_back(1);
    }

    int unclosed = 0, unopen = n;
    int ans = 0;

    for(int val = 0; val < n * 2; ++ val){
        if(unclosed <= k) ans = max(ans, values[val] * (unclosed + unopen));

        for(int stat: events[val]){
            if(stat == 1){
                --unclosed;
            }
        }
        for(int stat: events[val]){
            if(stat == 0){
                unclosed++;
                --unopen;
            }
        }
    }

    cout << ans << '\n';
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
