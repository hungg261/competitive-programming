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

    long long cur = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
        arr[i] = i == 1 ? x : (1LL * arr[i - 1] * a + b) % c;
        cur += arr[i];

        if(i >= k){
            cur -= arr[i - k];
            ans ^= cur;
        }
    }

    cout << ans << '\n';

    return 0;
}
