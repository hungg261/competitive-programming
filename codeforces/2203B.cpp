/******************************************************************************
Link: https://codeforces.com/contest/2203/problem/B
Code: 2203B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-21.47.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    cin >> s;
    int x = stoll(s);

    auto dsum = [&s](){
        int res = 0;
        for(char d: s){
            res += d - '0';
        }
        return res;
    };
    auto digitsum = [](int x){
        int res = 0;
        while(x > 0){
            res += x % 10;
            x /= 10;
        }
        return res;
    };

    int res = 0;
    while(digitsum(x) != digitsum(digitsum(x))){
        int chosen = -1, diff = -1;
        for(int i = 0; i < (int)s.size(); ++i){
            int d = (i == 0 ? s[i] - '1' : s[i] - '0');
            if(d > diff){
                chosen = i;
                diff = d;
            }
        }

        s[chosen] = chosen == 0 ? '1' : '0';
        x = stoll(s);
        ++res;
    }

    cout << res << '\n';
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
