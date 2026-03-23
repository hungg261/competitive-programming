#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> le, chan;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        if(cur & 1) le.push_back(cur);
        else chan.push_back(cur);
    }
    sort(begin(le), end(le));
    sort(begin(chan), end(chan));

    if(le.empty()){
        for(int i = 1; i <= n; ++i) cout << "0 ";
        cout << '\n';
        return;
    }

    if(chan.empty()){
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            if(i & 1) cout << le.back() << ' ';
            else cout << "0 ";
        }

        cout << '\n';
        return;
    }

    int l = (int)le.size() - 1, c = (int)chan.size() - 1;
    int sum = le[l--];
    cout << sum << ' ';

    for(int i = 2; i < n; ++i){
        if(c >= 0) sum += chan[c--];
        else{
            sum -= chan[++c];
            l -= 2;
        }

        cout << (sum % 2 == 0 ? 0 : sum) << ' ';
    }

    if(l >= 0) sum += le[l--];
    if(c >= 0) sum += chan[c--];

    cout << (sum % 2 == 0 ? 0 : sum) << '\n';
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
