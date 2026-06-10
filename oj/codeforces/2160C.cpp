#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
    int n;
    cin >> n;

    int ctz = __builtin_ctzll(n);

    string bin;
    while(n > 0){
        bin += (n & 1) + '0';
        n >>= 1;
    }
    while(ctz--) bin += '0';
    if(bin.empty()) bin = "0";

    string temp = bin;
    reverse(begin(bin), end(bin));

    if(bin == temp && (bin.size() % 2 == 0 || bin[bin.size() >> 1] != '1')){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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
