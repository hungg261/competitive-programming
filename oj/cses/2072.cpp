/******************************************************************************
Link: https://cses.fi/problemset/task/2072
Code: 2072
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-20-20.25.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

namespace iTreap{

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Node{
    char val;
    int priority, sz;
    Node *l, *r;

    Node() = default;
    Node(char _v, Node *_l = nullptr, Node *_r = nullptr):
        val(_v), priority(rng()), sz(1), l(_l), r(_r){}

    void update(){
        sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
    }
};

void split(Node *t, int k, Node* &l, Node* &r){
    if(!t){ l = r = nullptr; return; }

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

void merge(Node* &t, Node* l, Node* r){
    if(!l || !r) t = l ? l : r;
    else if(l->priority > r->priority){
        t = l;
        merge(t->r, l->r, r);
    }
    else{
        t = r;
        merge(t->l, l, r->l);
    }

    if(t) t->update();
}

void print(Node *t){
    if(!t) return;

    print(t->l);
    cout << t->val;
    print(t->r);
}

}

const int MAXN = 2e5;
int n, m;
string s;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    cin >> s;

    iTreap::Node* root = nullptr;
    for(char c: s) iTreap::merge(root, root, new iTreap::Node(c));

    while(m--){
        int l, r;
        cin >> l >> r;

        iTreap::Node *T1, *T2, *T3;

        iTreap::split(root, r, T1, T3);
        iTreap::split(T1, l - 1, T1, T2);

        iTreap::merge(root, T1, T3);
        iTreap::merge(root, root, T2);
    }

    print(root);
    cout << endl;

    return 0;
}
