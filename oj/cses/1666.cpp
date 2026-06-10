#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int parent[MAXN + 5], sz[MAXN + 5];

void create_set(int v){
    parent[v] = v;
}

int find_set(int v){
    if(parent[v] == v) return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int u,int v){
    int a = find_set(u), b = find_set(v);
    if(a == b) return;

    if(sz[a] < sz[b]) return;
    parent[b] = a;
    sz[a] += sz[b];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        create_set(i);
    }

    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;

        union_sets(u, v);
    }

    unordered_set<int> get_unique;
    for(int i = 1; i <= n; ++i){
        get_unique.insert(find_set(i));
    }


    cout << (int)get_unique.size() - 1 << '\n';
    int prv = -1;
    for(int city: get_unique){
        if(prv != -1){
            cout << prv << ' ' << city << '\n';
        }
        prv = city;
    }
    return 0;
}
