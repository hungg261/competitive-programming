#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
int arr[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int ans = 0;
    deque<int> dq;

    for(int i = 1; i <= n; ++i){
        arr[i] = i == 1 ? x : (1LL * arr[i - 1] * a + b) % c;

        while(!dq.empty() && i - dq.back() + 1 > k) dq.pop_back();
        while(!dq.empty() && arr[dq.front()] > arr[i]) dq.pop_front();
        dq.push_front(i);

        if(i >= k){
            ans ^= arr[dq.back()];
        }
    }

    cout << ans << '\n';

    return 0;
}
