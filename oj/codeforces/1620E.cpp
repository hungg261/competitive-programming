/******************************************************************************
Link: https://codeforces.com/contest/1620/problem/E
Code: 1620E
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-30-11.58.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *nxt;
    int value;

    Node(int _v = -1): nxt(nullptr), value(_v){}

    int update(){
        if(nxt == nullptr) return value;

        int v = value = nxt->update();
        nxt = nullptr;

        return v;
    }
};

const int MAXN = 5e5, MAXVAL = 5e5;
int last[MAXVAL + 5];
Node *nodes[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;

    memset(last, -1, sizeof last);
    for(int i = 1; i <= q; ++i) nodes[i] = new Node();

    int idx = 0;
    for(int i = 1; i <= q; ++i){
        int type;
        cin >> type;

        if(type == 1){
            int x;
            cin >> x;

            ++idx;
            nodes[idx]->value = x;

            if(last[x] != -1){
                nodes[last[x]]->nxt = nodes[idx];
            }
            last[x] = idx;
        }
        else{
            int x, y;
            cin >> x >> y;

            if(x == y || last[x] == -1) continue;

            nodes[last[x]]->value = y;
            if(last[y] != -1)
                nodes[last[x]]->nxt = nodes[last[y]];
            else last[y] = last[x];

            last[x] = -1;
        }
    }

    for(int i = 1; i <= idx; ++i){
        nodes[i]->update();
        cout << nodes[i]->value << " ";
    }

    return 0;
}
