#include<bits/stdc++.h>
using namespace std;

void solve(){
    string S;
    cin >> S;

    int up2 = 0, up3 = 0;
    int mod9 = 0;
    for(char c: S){
        if(c == '2') ++up2;
        if(c == '3') ++up3;
        mod9 = (mod9 + c - '0') % 9;
    }

    for(int c0 = 0; c0 <= min(up2, 9); ++c0){
        for(int c1 = 0; c1 <= min(up3, 9); ++c1){
            if((mod9 + 2 * c0 + 6 * c1) % 9 == 0){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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
