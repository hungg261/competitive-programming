/******************************************************************************
Link: https://codeforces.com/contest/2276/problem/E
Code: 2276E
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-09.17.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    n = s.size();

    vector<vector<int>> nxt(n + 1);
    nxt[n] = vector<int>(10, n);
    for(int i = n - 1; i >= 0; --i){
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - '0'] = i;
    }

    auto find = [&nxt](int st, const string &t) -> int {
        for(int c: t){
            c -= '0';
            st = nxt[st][c];
        }
        return st;
    };

    vector<int> diff1(n + 1, 0), diff2(n + 1, 0);
    auto add = [](int l, int r, int val, vector<int> &diff){
        diff[r + 1] -= val;
        diff[l] += val;
    };

    auto add_f = [&](int l, int r, int a = -1, int b = LLONG_MAX){
        if(b == LLONG_MAX) b = r + 1;
        add(l, r, a, diff1);
        add(l, r, b, diff2);
    };

    auto add_contrib = [&](int l, int A, int B){
        add_f(l, A - 1, 0, B - A + 1);
        add_f(A, B);
    };

    for(int l = 0; l < n; ++l){
        int r25 = find(l, "2025"), r26 = find(l, "2026");
        if(r25 < r26){
            add_contrib(l, l, r25 - 1);
            add_contrib(l, r26, n - 1);
        }
        else add_contrib(l, l, n - 1);
    }

    int p1 = 0, p2 = 0;
    for(int i = 0; i < n; ++i){
        p1 += diff1[i];
        p2 += diff2[i];

        cout << i * p1 + p2 << " ";
    }
    cout << "\n";
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
