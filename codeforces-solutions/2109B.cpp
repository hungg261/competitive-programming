#include<bits/stdc++.h>
using namespace std;

#define int long long

int f(int x){
    if(x == 1) return 0;
    return f((x + 1) / 2) + 1;
}

int f(int n, int m){
    return f(n) + f(m);
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int ans = f(n, m);
    vector<int> S;
    int s1 = f(a, m), s2 = f(n - a + 1, m),
        s3 = f(n, b), s4 = f(n, m - b + 1);

    S.push_back(s1);
    S.push_back(s2);
    S.push_back(s3);
    S.push_back(s4);

    int best = *min_element(begin(S), end(S));
    ans = min(ans, best + 1);
    cout << ans << '\n';
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
