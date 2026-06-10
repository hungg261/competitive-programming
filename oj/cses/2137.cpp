/******************************************************************************
Link: https://cses.fi/problemset/task/2137
Code: 2137
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-17-10.04.35
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 3000;
static const int W = 64;
static const int B = (MAXN + W - 1) / W;

uint64_t a[MAXN][B];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            if (s[j] == '1'){
                a[i][j >> 6] |= 1ULL << (j & 63);
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int cnt = 0;
            for (int k = 0; k < B; k++){
                cnt += __builtin_popcountll(a[i][k] & a[j][k]);
            }
            ans += 1LL * cnt * (cnt - 1) / 2;
        }
    }

    cout << ans << '\n';

    return 0;
}
