/******************************************************************************
Link: https://codeforces.com/contest/2069/problem/D
Code: 2069D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-20-23.32.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    s = "#" + s;

    auto find_first_not_palin = [&]() -> int {
        for(int i = 1; i * 2 <= n; ++i){
            if(s[i] != s[n - i + 1]){
                return i;
            }
        }
        return 0;
    };

    int f;
    if(!(f = find_first_not_palin())){
        cout << "0\n";
        return;
    }

    s.erase(end(s) - f + 1, end(s));
    s.erase(begin(s), begin(s) + f);

    n = s.size();
    s = "#" + s;

    auto check = [&](int mid){
        array<int, 26> freq{};
        for(int i = 1; i <= mid; ++i) freq[s[i] - 'a']++;

        for(int i = mid + 1; i <= n; ++i){
            if(n - i + 1 > mid){
                if(s[n - i + 1] != s[i]) return false;
            }
            else if(--freq[s[i] - 'a'] < 0)
                return false;
        }

        bool odd = 0;
        for(int c = 0; c < 26; ++c){
            if(freq[c] & 1){
                if(odd) return false;
                odd = 1;
            }
        }

        return true;
    };

    auto binsearch = [&](){
        int l = 1, r = n, res = 1e9;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    };

    int res = binsearch();

    reverse(begin(s) + 1, end(s));
    res = min(res, binsearch());

    cout << res << "\n";
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
