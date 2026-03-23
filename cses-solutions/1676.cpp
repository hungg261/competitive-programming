/******************************************************************************
Link: https://cses.fi/problemset/task/1676
Code: 1676
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-26-21.41.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int parent[MAXN + 5], sz[MAXN + 5];

void create(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

int union_sets(int u, int v){
    int a = find_set(u), b = find_set(v);
    if(a == b) return -1;

    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];

    return sz[a];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1676.INP","r",stdin);
    //freopen("1676.OUT","w",stdout);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) create(i);

    int cnt = n, maxc = 1;
    while(m--){
        int a, b;
        cin >> a >> b;

        if(find_set(a) != find_set(b)) --cnt;
        maxc = max(maxc, union_sets(a, b));

        cout << cnt << ' ' << maxc << '\n';
    }

    return 0;
}
