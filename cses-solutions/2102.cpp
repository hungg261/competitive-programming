/******************************************************************************
Link: https://cses.fi/problemset/task/2102
Code: 2102
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-13-22.08.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXK = 5e5;
int n, k;
string matches[MAXK + 5];
string S;

struct AhoCorasick{
    struct Node{
        int nxt[26];
        int link;
        int occurrences;
        vector<int> ends;

        Node(){
            memset(nxt, -1, sizeof nxt);
            occurrences = 0;
            link = -1;
        }
    };

    vector<Node> T;
    vector<vector<int>> adj;
    int root;

    AhoCorasick(){
        T.emplace_back();
        root = 0;
    }

    void add(int idx, const string& s){
        int p = root;
        for(int c: s){
            c -= 'a';

            if(T[p].nxt[c] == -1){
                T[p].nxt[c] = T.size();

                T.emplace_back();
            }
            p = T[p].nxt[c];
        }

        T[p].ends.push_back(idx);
    }

    void construct(){
        T[root].link = root;
        queue<int> que;

        for(int c = 0; c < 26; ++c){
            int v = T[root].nxt[c];
            if(v != -1){
                T[v].link = root;
                que.push(v);
            }
            else{
                T[root].nxt[c] = root;
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int c = 0; c < 26; ++c){
                int v = T[u].nxt[c];
                if(v != -1){
                    T[v].link = T[T[u].link].nxt[c];
                    que.push(v);
                }
                else{
                    T[u].nxt[c] = T[T[u].link].nxt[c];
                }
            }
        }

        adj.resize(T.size());
        for(int i = 1; i < T.size(); ++i){
            adj[T[i].link].push_back(i);
        }
    }

    int dfs(int u, vector<int>& res){
        int occ = T[u].occurrences;
        for(int v: adj[u]){
            occ += dfs(v, res);
        }

        for(int id: T[u].ends){
            res[id] = occ;
        }

        return occ;
    }

    void Search(const string& Text, vector<int>& res){
        int p = root;
        for(int c: Text){
            c -= 'a';

            p = T[p].nxt[c];
            if(p != -1){
                T[p].occurrences++;
            }
        }

        dfs(root, res);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2102.INP","r",stdin);
    //freopen("2102.OUT","w",stdout);
    cin >> S;
    n = S.size();

    cin >> k;
    AhoCorasick aho;
    for(int i = 0; i < k; ++i){
        cin >> matches[i];
        aho.add(i, matches[i]);
    }

    aho.construct();

    vector<int> res(k, 0);
    aho.Search(S, res);

    for(int i = 0; i < k; ++i){
        cout << (res[i] > 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}

/*
aybabtu
3
bab
abc
ayba

gcatcg
4
acc
atc
cat
gcg

acdefg
3
acd
cd
fg

abc
3
abc
bc
c
*/
