#include<bits/stdc++.h>
using namespace std;

struct Trie{
    struct Node{
        int nxt[26];
        int cnt;

        Node(){
            memset(nxt, -1, sizeof nxt);
            cnt = 0;
        }
    };

    vector<Node> T;
    int root;

    Trie(){
        T.emplace_back();
        root = 0;
    }

    void add(string s){
        int p = root;
        for(int ch: s){
            ch -= 'a';

            if(T[p].nxt[ch] == -1){
                T[p].nxt[ch] = T.size();
                T.emplace_back();
            }
            p = T[p].nxt[ch];
        }
        ++T[p].cnt;
    }

    bool exist(string s){
        int p = root;
        for(int ch: s){
            ch -= 'a';

            if(T[p].nxt[ch] == -1) return false;
            p = T[p].nxt[ch];
        }
        return T[p].cnt > 0;
    }

    Node& operator[] (int idx){ return T[idx]; }
    Node operator[] (int idx) const{ return T[idx]; }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int k;
    cin >> s >> k;

    Trie trie;
    while(k--){
        string cur; cin >> cur;
        trie.add(cur);
    }

    int n = s.size();
    vector<int> dp(n + 1);
    dp[n] = 1;

    const int MOD = 1e9 + 7;
    for(int i = n - 1; i >= 0; --i){
        int p = trie.root;
        for(int j = i; j < n; ++j){
            int ch = s[j] - 'a';

            if(trie[p].nxt[ch] == -1) break;
            p = trie[p].nxt[ch];

            dp[i] += 1LL * dp[j + 1] * trie[p].cnt % MOD; dp[i] %= MOD;
        }
    }

    cout << dp[0] << '\n';

    return 0;
}
