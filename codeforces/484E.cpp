/******************************************************************************
Link: https://codeforces.com/contest/484/problem/E
Code: 484E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-07-21.09.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    struct Node{
        int len = 1, maxPre = 0, maxSuf = 0, maxLen = 0;

        static Node Identity(){
            return {0, 0, 0, 0};
        }

        Node merge(const Node& other){
            if(this->len == 0) return other;
            if(other.len == 0) return *this;

            Node res;
            res.len = this->len + other.len;

            res.maxPre = this->maxPre;
            if(this->maxPre == this->len){
                res.maxPre = this->len + other.maxPre;
            }

            res.maxSuf = other.maxSuf;
            if(other.maxSuf == other.len){
                res.maxSuf = other.len + this->maxSuf;
            }

            res.maxLen = max({this->maxLen, other.maxLen, this->maxSuf + other.maxPre});

            return res;
        }
    };

    int n;
    vector<Node> nodes;

    SegmentTree() = default;
    SegmentTree(int sz): n(sz){
        nodes.resize(sz * 4 + 1);
    }

    void update(int id, int l, int r, int idx){
        if(r < idx || idx < l) return;

        if(l == r){
            nodes[id] = {1, 1, 1, 1};
            return;
        }

        int mid = (l + r) >> 1;
        update(id << 1, l, mid, idx);
        update(id << 1 | 1, mid + 1, r, idx);
        nodes[id] = nodes[id << 1].merge(nodes[id << 1 | 1]);
    }

    Node get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return Node::Identity();
        if(u <= l && r <= v) return nodes[id];

        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v).merge(get(id << 1 | 1, mid + 1, r, u, v));
    }
};

const int MAXN = 1e5, MAXM = 1e5;
int n, sz;
vector<int> store;
pair<int, int> h[MAXN + 5];

int q, l[MAXN + 5], r[MAXN + 5], w[MAXN + 5];
vector<int> candidates[MAXN + 5];
int L[MAXN + 5], R[MAXN + 5];

void solve(){
    while(true){
        bool changed = false;
        for(int qr = 1; qr <= q; ++qr){
            if(L[qr] >= R[qr]) continue;

            int mid = (L[qr] + R[qr] + 1) >> 1;
            candidates[mid].push_back(qr);
            changed = true;
        }
        if(!changed) break;

        SegmentTree ST(n);
        int j = n;
        for(int i = sz - 1; i >= 0; --i){
            while(j >= 1 && h[j].first == store[i])
                ST.update(1, 1, n, h[j--].second);

            for(int qr: candidates[i]){
                if(ST.get(1, 1, n, l[qr], r[qr]).maxLen >= w[qr])
                    L[qr] = i;
                else R[qr] = i - 1;
            }
        }

        for(int i = 0; i < sz; ++i)
            candidates[i].clear();
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> h[i].first;
        h[i].second = i;
    }
    sort(h + 1, h + n + 1);
    for(int i = 1; i <= n; ++i) store.push_back(h[i].first);
    store.erase(unique(begin(store), end(store)), end(store));
    sz = store.size();

    cin >> q;
    for(int qr = 1; qr <= q; ++qr){
        cin >> l[qr] >> r[qr] >> w[qr];
        L[qr] = 0; R[qr] = sz - 1;
    }

    solve();

    for(int qr = 1; qr <= q; ++qr){
        cout << store[L[qr]] << "\n";
    }

    return 0;
}
