#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e4;
int arr[MAXN + 5];

inline int dist(int a, int b){
    return __builtin_popcount(a ^ b);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        string bin; cin >> bin;
        for(int j = 0; j < k; ++j){
            arr[i] |= (bin[j] - '0') << j;
        }
    }

    int ans = 1e9;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            ans = min(ans, dist(arr[i], arr[j]));
        }
    }

    cout << ans << '\n';

    return 0;
}
