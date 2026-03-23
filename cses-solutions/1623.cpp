#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 20;
int n, p[MAXN + 5];
long long total_sum = 0;

void solve(){
    long long ans = INT_MAX;
    for(int mask = 0; mask < (1 << n); ++mask){
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            if(mask & (1 << i)){
                sum += p[i];
            }
        }

        ans = min(ans, abs(total_sum - 2LL * sum));
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        total_sum += p[i];
    }

    solve();
    return 0;
}
