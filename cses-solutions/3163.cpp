/******************************************************************************
Link: https://cses.fi/problemset/task/3163
Code: 3163
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-28-08.17.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
vector<int> nodes[MAXN * 2 + 1];
int arr[MAXN + 5], n;

void build(){
    for(int i = 0; i < n; ++i){
        nodes[i + n].push_back(arr[i + 1]);
    }

    for(int id = n - 1; id > 0; --id){
        nodes[id].resize(nodes[id << 1].size() + nodes[id << 1 | 1].size());
        merge(begin(nodes[id << 1]), end(nodes[id << 1]), begin(nodes[id << 1 | 1]), end(nodes[id << 1 | 1]), begin(nodes[id]));
    }
}

int get(int l, int r, int c, int d){
    --l;
    l += n; r += n;

    int res = 0;
    while(l < r){
        if(l & 1){
            res += upper_bound(begin(nodes[l]), end(nodes[l]), d) - lower_bound(begin(nodes[l]), end(nodes[l]), c);
            l++;
        }
        if(r & 1){
            --r;
            res += upper_bound(begin(nodes[r]), end(nodes[r]), d) - lower_bound(begin(nodes[r]), end(nodes[r]), c);
        }
        l >>= 1; r >>= 1;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("3163.INP","r",stdin);
//    freopen("3163.OUT","w",stdout);
    int q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    build();

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << get(a, b, c, d) << '\n';
    }

    return 0;
}
