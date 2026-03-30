/******************************************************************************
Link: https://codeforces.com/contest/2092/problem/D
Code: 2092D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-28-21.21.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    Node* nxt;

    Node(char v): c(v), nxt(nullptr) {}

    void connect(Node* other){
        nxt = other;
    }

    bool eq(const Node* other) const{
        return c == other->c;
    }
};

int v(char c){
    if(c == 'L') return 0;
    if(c == 'I') return 1;
    if(c == 'T') return 2;
    throw "weird";
}

char other(char a, char b){
    set<char> S = {'L', 'I', 'T'};
    S.erase(a);
    S.erase(b);
    return *S.begin();
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    Node* head = new Node(s[0]);
    Node *cur = head;
    for(int i = 1; i < n; ++i){
        Node *added = new Node(s[i]);
        cur->connect(added);
        cur = added;
    }

    int cnt[3] = {};
    for(char c: s) ++cnt[v(c)];

    int mx = *max_element(cnt, cnt + 3);
    vector<int> op;
    for(int r = 1; r <= 2 * n; ++r){
        if(cnt[0] == cnt[1] && cnt[1] == cnt[2]) break;

        Node *cur = head, *prv = nullptr;
        int idx = 1;
        while(cur != nullptr){
            if(prv != nullptr){
                char add_c = other(cur->c, prv->c);
                if(cnt[v(add_c)] < mx && !cur->eq(prv)){
                    op.push_back(idx - 1);

                    Node* added = new Node(add_c);
                    prv->connect(added);
                    added->connect(cur);

                    ++cnt[v(added->c)];
                    goto found;
                }
            }

            prv = cur;
            cur = cur->nxt;
            ++idx;
        }

        cur = head, prv = nullptr;
        idx = 1;
        while(cur != nullptr){
            if(prv != nullptr){
                char add_c = other(cur->c, prv->c);
                if(cnt[v(add_c)] == mx && !cur->eq(prv)){
                    op.push_back(idx - 1);

                    Node* added = new Node(add_c);
                    prv->connect(added);
                    added->connect(cur);

                    ++cnt[v(added->c)];
                    ++mx;
                    goto found;
                }
            }

            prv = cur;
            cur = cur->nxt;
            ++idx;
        }
        found:;
    }

    if(!(cnt[0] == cnt[1] && cnt[1] == cnt[2])) cout << "-1\n";
    else{
        cout << op.size() << "\n";
        for(int o: op) cout << o << "\n";
    }
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
