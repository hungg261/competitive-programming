#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e7;
int arr[MAXN + 5];
int pre[MAXN + 5], suf[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    arr[1] = pre[1] = x;
    for(int i = 2; i <= n; ++i){
        arr[i] = (a * arr[i - 1] + b) % c;

        pre[i] = i % k == 1 ? arr[i] : pre[i - 1] | arr[i];
    }

    suf[n] = arr[n];
    for(int i = n - 1; i >= 1; --i){
        suf[i] = i % k == 0 ? arr[i] : suf[i + 1] | arr[i];
    }

    int ans = 0;

    if(k == 1){
        for(int i = 1; i <= n; ++i){
            ans ^= arr[i];
        }
    }
    else{
        for(int i = k; i <= n; ++i){
            ans ^= (suf[i - k + 1] | pre[i]);
        }
    }

    cout << ans << '\n';

    return 0;
}
