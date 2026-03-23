#include<bits/stdc++.h>
#define it(A) begin((A)), end((A))
using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    if(a + b > n || (!a ^ !b)){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int draws = n - a - b;
    int left = n - draws;

    for(int i = 1; i <= n; ++i) cout << i << ' ';
    cout << '\n';

    for(int i = 1; i <= b; ++i) cout << a + i << ' ';
    for(int i = 1; i <= a; ++i) cout << i << ' ';
    for(int i = left + 1; i <= n; ++i) cout << i << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
