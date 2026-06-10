/******************************************************************************
Link: https://cses.fi/problemset/task/3273
Code: 3273
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-14-07.58.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n;
char mp[200005];

char ask(int i){
    i = (i - 1 + n) % n + 1;
    if(mp[i]) return mp[i];

    cout << "? " << i << endl;

    char c;
    cin >> c;

    return mp[i] = c;
}

void solve(){
    int l = 1, r = n + 1, res = -1;

    char c_left = ask(1);
    while(l <= r){
        int mid = (l + r) >> 1;

        int asked = mid > n ? 1 : mid;

        char c_mid = ask(asked);

        res = (asked - 2 + n) % n + 1;
        if(mid % 2 != 0){
            if(c_mid == c_left) l = mid + 1;
            else r = mid - 1;
        }
        else{
            if(c_mid == c_left) r = mid - 1;
            else l = mid + 1;
        }
    }

    if(ask(res) == ask(res + 1)) cout << "! " << res << endl;
    else cout << "! " << res % n + 1 << endl;
}

signed main(){

    cin >> n;

    solve();

    return 0;
}
