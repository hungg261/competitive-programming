/******************************************************************************
Link: https://codeforces.com/problemset/problem/1303/D
Code: 1303D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-02-16.59.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXLG = 61;

void solve(){
    int S, n;
    cin >> S >> n;

    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    if(sum < S){
        cout << "-1\n";
        return;
    }

    vector<int> b(MAXLG + 1, 0);
    for(int x: a)
        b[__lg(x)]++;

    int res = 0;
    for(int bit = 0; bit <= MAXLG; ++bit){
        if(S >> bit & 1){
            if(b[bit] > 0) --b[bit];
            else{
                int nxt = bit;
                for(; nxt <= MAXLG && b[nxt] == 0; ++nxt){
                    ++b[nxt];
                    ++res;
                }
                --b[nxt];
            }
        }

        if(bit < MAXLG)
            b[bit + 1] += b[bit] / 2;
    }

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
