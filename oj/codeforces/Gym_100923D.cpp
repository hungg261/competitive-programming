/******************************************************************************
Link: https://codeforces.com/gym/100923/problem/D
Code: Gym_100923D
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-30-10.02.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct AhoCorasick{
    struct Node{
        int nxt[26];
        int link, dist;
        bool end;
        vector<int> ends;

        Node(){
            memset(nxt, -1, sizeof nxt);
            link = -1;
            dist = 0;
            end = false;
        }
    };

    vector<Node> T;
    vector<vector<int>> adj;
    int root = 0;
    AhoCorasick(){
        T.emplace_back();
    }

    void add(const string& s){
        int p = root;
        for(int c: s){
            c -= 'a';

            if(T[p].nxt[c] == -1){
                T[p].nxt[c] = T.size();
                T.emplace_back();
                T[T[p].nxt[c]].dist = T[p].dist + 1;
            }
            p = T[p].nxt[c];
        }

        T[p].end = true;
    }

    void build(){
        T[root].link = root;
        queue<int> que;

        for(int c = 0; c < 26; ++c){
            int v = T[root].nxt[c];
            if(v != -1){
                T[v].link = root;
                que.push(v);
            }
            else T[root].nxt[c] = root;
        }

        while(!que.empty()){
            int u = que.front(); que.pop();

            for(int c = 0; c < 26; ++c){
                int v = T[u].nxt[c];
                if(v != -1){
                    T[v].link = T[T[u].link].nxt[c];
                    que.push(v);
                }
                else T[u].nxt[c] = T[T[u].link].nxt[c];
            }
        }

        adj.resize(T.size());
        for(int i = 1; i < (int)T.size(); ++i){
            adj[T[i].link].push_back(i);
        }
    }

    void dfs(int u){
        for(int v: adj[u]){
            dfs(v);
            for(int x: T[v].ends)
                T[u].ends.push_back(x);
        }
    }

    void search(const string& TXT){
        int p = root;
        int idx = 0;
        for(int c: TXT){
            c -= 'a';
            ++idx;

            p = T[p].nxt[c];
            if(p != -1){
                T[p].ends.push_back(idx);
            }
        }

        dfs(root);
    }

    void debug(){
        for(int p = 0; p < (int)T.size(); ++p){
            if(!T[p].end) continue;

            cerr << p << " | " << T[p].dist << " ===\n";
            for(int x: T[p].ends){
                cerr << x - T[p].dist + 1 << " " << x << "\n";
            }
            cerr << "===========\n";
        }
    }
};

void solve(){
    AhoCorasick aho;

    int n;
    string TXT;
    vector<int> c;

    cin >> n >> TXT;
    n = TXT.size();
    c.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }

    int q;
    cin >> q;
    while(q--){
        string pattern;
        cin >> pattern;

        aho.add(pattern);
    }

    aho.build();
    aho.search(TXT);

    aho.debug();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}
