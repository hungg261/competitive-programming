#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 1e5;
int n;
string s;
vector<int> adj[MAXN + 5];

void dfs(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }
}

void solve(){
    cin >> n;
    for(int u = 1; u <= n; ++u){
        adj[u].clear();
    }
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    s = "#" + s;

    auto filler = [&](int sub = 0){
        int res = 0, filled = 0;
        for(int u = 1; u <= n; ++u){
            if(adj[u].size() == 1){
                if(s[u] == '?') ++filled;
                else if(s[u] != s[1]) ++res;
            }
        }

        return res + (filled - sub + 1) / 2;
    };

    int ans = 0;
    if(s[1] != '?') ans += filler();
    else{
        int delta = 0;
        for(int u = 2; u <= n; ++u){
            if(adj[u].size() != 1) continue;
            if(s[u] == '0') ++delta;
            else if(s[u] == '1') --delta;
        }

        s[1] = delta > 0 ? '1' : '0';
        if(delta == 0){
            int cnt = 0;
            for(int u = 2; u <= n; ++u){
                if(adj[u].size() > 1 && s[u] == '?')
                    ++cnt;
            }

            ans += filler(cnt % 2 == 0);
        }
        else{
            ans += filler(1);
        }

    }

    cout << ans << '\n';
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
