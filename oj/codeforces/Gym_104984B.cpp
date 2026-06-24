#include<bits/stdc++.h>
using namespace std;

const int MAX = 5e5;
string s, t;
int n, m;

int dp[2][MAX + 5];
void compute(int b){
    vector<vector<int>> f(n + 1, vector<int>(26, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 26; ++j){
            f[i][j] = max(f[i][j], f[i - 1][j]);

            if(s[i] == t[f[i - 1][j] + 1])
                f[i][s[i] - 'a'] = max(f[i][s[i] - 'a'], f[i - 1][j] + 1);
        }

        dp[b][i] = *max_element(begin(f[i]), end(f[i]));
    }
}

void solve(){
    if(s == t){
        cout << "YES\n";
        return;
    }

    compute(0);
    reverse(begin(s), end(s)); reverse(begin(t), end(t));
    compute(1);

    reverse(begin(s), end(s)); reverse(begin(t), end(t));
    for(int i = 1; i <= n; ++i){
        if(i % 2 == 0 && dp[0][i - 1] + dp[1][n - i] >= m){
            cout << "YES\n";
            return;
        }
        if(s[i] != t[i]) break;
    }

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> t;
    n = s.size(); m = t.size();
    s = "#" + s + "#"; t = "#" + t + "#";

    solve();

    return 0;
}
