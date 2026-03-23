#include<bits/stdc++.h>
using namespace std;

void minimize(int& x, int y){ x = min(x, y); }
void maximize(int& x, int y){ x = max(x, y); }

const int MAXN = 1e6;
int nxt[MAXN + 5][26];
int n, k, q;
string s;

int dp[MAXN + 5];
void compute(){
    int last[26] = {};
    for(int c = 0; c < k; ++c) last[c] = n + 1;

    for(int i = n + 1; i >= 0; --i){
        for(int c = 0; c < k; ++c){
            nxt[i][c] = last[c];
        }

        if(i > 0) last[s[i] - 'a'] = i;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[n + 1] = 0;
    for(int i = n; i >= 0; --i){
        for(int c = 0; c < k; ++c){
            dp[i] = min(dp[i], dp[nxt[i][c]] + 1);
        }
    }
}

void solve(){
    string t;
    cin >> t;

    int pos = 0;
    for(char c: t){
        pos = nxt[pos][c - 'a'];
    }

    cout << dp[pos] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cin >> s;
    cin >> q;
    s = "#" + s;

    compute();

    while(q--){
        solve();
    }

    return 0;
}
