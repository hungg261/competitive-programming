/******************************************************************************
Link: https://codeforces.com/contest/2194/problem/C
Code: 2194C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-09-02.22.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<string> arr(k);
    for(int i = 0; i < k; ++i){
        cin >> arr[i];
    }

    vector<int> masks(n);
    for(int j = 0; j < n; ++j){
        masks[j] = 0;
        for(int i = 0; i < k; ++i){
            masks[j] |= 1 << (arr[i][j] - 'a');
        }
    }

    vector<int> divisors;
    for(int d = 1; d * d <= n; ++d){
        if(n % d != 0) continue;

        divisors.push_back(d);
        if(d * d != n) divisors.push_back(n / d);
    }
    sort(begin(divisors), end(divisors));

    for(int len: divisors){
        bool ok = true;
        for(int s = 0; s < len; ++s){
            int mask = ~0;
            for(int j = s; j < n; j += len){
                mask &= masks[j];
            }

            if(mask == 0){
                ok = false;
                break;
            }
        }

        if(!ok) continue;

        string rep;
        for(int s = 0; s < len; ++s){
            int mask = ~0;
            for(int j = s; j < n; j += len){
                mask &= masks[j];
            }

            rep += (char)(__builtin_ctz(mask) + 'a');
        }

        for(int cnt = 0; cnt < n / len; ++cnt) cout << rep;
        cout << '\n';
        return;
    }
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
