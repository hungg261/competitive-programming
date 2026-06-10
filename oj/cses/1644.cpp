#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        prefix[i] = prefix[i - 1] + cur;
    }

    deque<int> dq;
    vector<int> windows(n + 1);
    int window_sz = b - a + 1;

    for(int i = 0; i <= n; ++i){
        if(!dq.empty() && i - dq.back() + 1 > window_sz) dq.pop_back();
        while(!dq.empty() && prefix[dq.front()] >= prefix[i]) dq.pop_front();

        dq.push_front(i);

            windows[i] = prefix[dq.back()];
    }

    int ans = -1e18;
    for(int i = a; i <= n; ++i){
        ans = max(ans, prefix[i] - windows[i - a]);
    }

    cout << ans << '\n';

    return 0;
}
