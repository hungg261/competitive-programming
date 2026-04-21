/******************************************************************************
Link: https://cses.fi/problemset/task/2074
Code: 2074
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-21-09.03.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

namespace iTreap{

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
    long long val, sum;
    int priority, sz;
    bool rev;
    Node *l, *r;

    Node(long long _v):
        val(_v), sum(_v), priority(rng()), sz(1), rev(false), l(nullptr), r(nullptr){}

    void update(){
        this->sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
        this->sum = val + (l ? l->sum : 0) + (r ? r->sum : 0);
    }
};

void push(Node* &t){
    if(t && t->rev){
        swap(t->l, t->r);
        t->rev = false;

        if(t->l) t->l->rev ^= 1;
        if(t->r) t->r->rev ^= 1;
    }
}

void split(Node *t, int k, Node* &l, Node* &r){
    if(!t){ l = r = nullptr; return; }
    push(t);

    int leftSz = t->l ? t->l->sz : 0;
    if(leftSz < k){
        l = t;
        split(t->r, k - leftSz - 1, l->r, r);
    }
    else{
        r = t;
        split(t->l, k, l, r->l);
    }

    t->update();
}

void merge(Node* &t, Node *l, Node *r){
    push(l);
    push(r);

    if(!l || !r) t = l ? l : r;
    else if(l->priority > r->priority){
        t = l;
        merge(t->r, l->r, r);
    }
    else{
        t = r;
        merge(t->l, l, r->l);
    }

    t->update();
}

}
using namespace iTreap;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    Node *root = nullptr;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        merge(root, root, new Node(cur));
    }

    while(q--){
        int type, l, r;
        cin >> type >> l >> r;

        Node *T1, *T2, *T3;
        split(root, r, T2, T3);
        split(T2, l - 1, T1, T2);

        if(type == 1) T2->rev ^= 1;
        else cout << T2->sum << "\n";

        merge(root, T1, T2);
        merge(root, root, T3);
    }

    return 0;
}
