/******************************************************************************
Link: https://oj.vnoi.info/problem/gss
Code: gss
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-23-20.57.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 50000;
const int INF = 1e18;
struct Node{
    int maxPre, maxSuf, Sum, maxSum;

    Node(): maxPre(-INF), maxSuf(-INF), Sum(0), maxSum(-INF){}
    Node(int val): maxPre(val), maxSuf(val), Sum(val), maxSum(val){}

    Node operator + (const Node& other) const{
        Node res;
        res.maxPre = max(maxPre, Sum + other.maxPre);
        res.maxSuf = max(maxSuf + other.Sum, other.maxSuf);
        res.Sum = Sum + other.Sum;
        res.maxSum = max({maxSum, other.maxSum, maxSuf + other.maxPre});
        return res;
    }
};

Node nodes[MAXN * 4 + 5];

void build(int id, int l, int r){
    if(l == r){
        int val;
        cin >> val;

        nodes[id] = Node(val);
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return Node();
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    build(1, 1, n);

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << get(1, 1, n, l, r).maxSum << '\n';
    }

    return 0;
}
