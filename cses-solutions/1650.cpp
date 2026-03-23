#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> x(n + 1);
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        prefix[i] = prefix[i - 1] ^ x[i];
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << (prefix[b] ^ prefix[a - 1]) << '\n';
    }
    return 0;
}
