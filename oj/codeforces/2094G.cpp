#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int q;
    cin >> q;

    int sz = 0;
    deque<int> arr[2];
    int sum = 0, res[2] = {};

    int cur = 0;

    while(q--){
        int s;
        cin >> s;

        if(s == 1){
            res[cur] = res[cur] - arr[cur].back() * (sz - 1) + (sum - arr[cur].back());
            arr[cur].push_front(arr[cur].back());
            arr[cur].pop_back();

            res[cur ^ 1] = res[cur ^ 1] + arr[cur ^ 1].front() * (sz - 1) - (sum - arr[cur ^ 1].front());
            arr[cur ^ 1].push_back(arr[cur ^ 1].front());
            arr[cur ^ 1].pop_front();
        }
        else if(s == 2){
            cur ^= 1;
        }
        else{
            int k;
            cin >> k;

            ++sz;
            res[cur] = res[cur] + k * sz;
            res[cur ^ 1] = res[cur ^ 1] + sum + k;

            arr[cur].push_back(k);
            arr[cur ^ 1].push_front(k);

            sum += k;
        }

        cout << res[cur] << '\n';
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
