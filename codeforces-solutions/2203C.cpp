/******************************************************************************
Link: https://codeforces.com/contest/2203/problem/C
Code: 2203C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-21.59.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(int n, int s, int m){
    int L = 0, R = 0;
    // t

    for (int k = 0; k <= 60; k++){
        int s_bit = (s >> k) & 1;
        int m_bit = (m >> k) & 1;

        if (m_bit == 0){
            int low = max(L, s_bit);
            if ((low & 1) != s_bit) low++;
            if (low > R) return false;

            int high = R;
            if ((high & 1) != s_bit) high--;
            if (high < low) return false;

            L = (low - s_bit) / 2;
            R = (high - s_bit) / 2;
        }
        else{
            int pL = (s_bit - L) & 1;
            int c_minL = pL;

            int c_maxL;
            if ((n & 1) == pL) c_maxL = n;
            else c_maxL = n - 1; // ??

            if (c_minL > c_maxL) return false;
            int newL = (c_minL + L - s_bit) / 2;

            int pR = (s_bit - R) & 1;
            int c_maxR;
            if ((n & 1) == pR) c_maxR = n;
            else c_maxR = n - 1;

            if (c_minL > c_maxR) return false;
            int newR = (c_maxR + R - s_bit) / 2;

            if (newL > newR) return false;
            L = newL;
            R = newR;
        }
    }

    return L <= 0 && 0 <= R;
}

void solve(){
    int s, m;
    cin >> s >> m;

    if((m & -m) > (s & -s)){
        cout << "-1\n";
        return;
    }

    // 1101 101

    int d = m & -m;

    int l = (s + m - 1) / m, r = s / d, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid, s, m)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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
