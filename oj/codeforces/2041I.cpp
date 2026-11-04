/******************************************************************************
Link: https://codeforces.com/problemset/problem/2041/I
Code: 2041I
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-09.28.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXQ = 1e6, MAXTOTAL = 2e6;
int Q;
struct Query{
    int type;
    string str;
    int num;
};
vector<Query> queries;
vector<int> str;
string strings[MAXQ + 1];
int ranked[MAXQ + 1];


inline int CHAR(char c){
    return c - 33;
}

struct State{
    int id;
    bool operator < (const State &other) const {
        int sz1 = strings[id].size(),
            sz2 = strings[other.id].size();

        if(sz1 != sz2) return sz1 > sz2;
        return ranked[id] < ranked[other.id];
    }
};

struct Node{
    int nxt[94];
    set<State> S;

    Node(){
        memset(nxt, -1, sizeof nxt);
    }
};

struct Trie{
    vector<Node> T;

    Trie(){
        T.reserve(MAXTOTAL + 5);
        T.emplace_back();
    }

    void add(int id){
        int p = 0;
        for(int c: strings[id]){
            c = CHAR(c);

            if(T[p].nxt[c] == -1){
                T[p].nxt[c] = T.size();
                T.emplace_back();
            }

            T[p].S.insert({id});
            p = T[p].nxt[c];
        }
        T[p].S.insert({id});
    }

    void pop(int id){
        int p = 0;
        for(int c: strings[id]){
            c = CHAR(c);
            T[p].S.erase({id});
            p = T[p].nxt[c];
        }
        T[p].S.erase({id});    }
};


void solve(){
    Trie trie;

    int p = 0;
    vector<int> sta = {p};
    for(int i = 0; i < Q; ++i){
        int type = queries[i].type;

        if(type == 0){
            trie.add(queries[i].num);
        }
        else if(type == 1){
            trie.pop(queries[i].num);
        }
        else if(type == 2){
            for(int c: queries[i].str){
                c = CHAR(c);
                if(trie.T[p].nxt[c] == -1){
                    trie.T[p].nxt[c] = trie.T.size();
                    trie.T.emplace_back();
                }

                sta.push_back(p = trie.T[p].nxt[c]);
            }
        }
        else if(type == 3){
            int k = queries[i].num;
            while((int)sta.size() > 1 && k > 0){
                sta.pop_back();
                --k;
            }
            p = sta.back();
        }

        if(p == -1 || trie.T[p].S.empty()){
            cout << "-1\n";
        }
        else{
            cout << trie.T[p].S.begin()->id << "\n";
//            for(auto s: trie.T[p].S){
//                cerr << "\t-> " << s.id << endl;
//            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> Q;
    queries.resize(Q);
    for(int i = 0; i < Q; ++i){
        string type;
        cin >> type;

        if(type == "add"){
            int id; string p;
            cin >> id >> p;

            queries[i] = {0, "", id};
            str.push_back(id);
            strings[id] = p;
        }
        else if(type == "delete"){
            int id; cin >> id;

            queries[i] = {1, "", id};
        }
        else if(type == "append"){
            string s; cin >> s;

            queries[i] = {2, s, -1};
        }
        else if(type == "backspace"){
            int c; cin >> c;

            queries[i] = {3, "", c};
        }
    }

    sort(begin(str), end(str), [&](int x, int y){ return strings[x] < strings[y] ||
                                                (strings[x] == strings[y] && x < y) ; });
    for(int i = 0; i < (int)str.size(); ++i){
        ranked[str[i]] = i;
    }

    solve();

    return 0;
}
