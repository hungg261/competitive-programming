#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n * 2 + 5), pre(n * 2 + 5, 0);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    for(int i = 1; i <= n * 2; ++i){
        pre[i] = pre[i - 1] + arr[i];
    }

    auto mapper = [&](int x){
        return make_pair((x - 1) % n + 1, (x - 1) / n + 1);
    };

    auto GSum = [&](int g, int idx){
        return pre[g + idx - 1] - pre[g - 1];
    };

    auto solver = [&](int X){
        int left, group;
        tie(left, group) = mapper(X);

        int res = pre[n] * (group - 1);
        res += GSum((group - 1) % n + 1, left);

        return res;
    };

    auto get = [&](int l, int r){
        return solver(r) - solver(l - 1);
    };

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << get(l, r) << '\n';
    }
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
