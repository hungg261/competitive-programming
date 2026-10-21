/******************************************************************************
Link: https://qoj.ac/problem/1662
Code: 1662
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-09.01.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
string str;

struct Node{
    vector<Node*> nxt;
    char v;

    Node(char _v): v(_v){}
};


int find_open(int r){
    for(int i = r; ; --i){
        if(str[i] == '(') return i;
    }
    return -1;
}


Node *_parse(int l, int r, int sz){
    if(l > r) return nullptr;

    if(str[l] == '(' && find_open(r) == l)
        return _parse(l + 1, r - 1, sz);

    if(str[r] == '+'){
        Node *node = _parse(l, r - 1, sz);
        node->nxt.push_back(node);
        return node;
    }
    else if(str[r] == '?'){
        Node *nxt = _parse(r + 1, sz, sz);
        Node *pre = _parse(l, r - 1, sz);

    }
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> str;


    return 0;
}
