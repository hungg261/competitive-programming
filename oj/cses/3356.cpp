/******************************************************************************
Link: https://cses.fi/problemset/task/3356
Code: 3356
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-16-20.59.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXQ = 2e5, INF = 1e9;
struct Query{
    int type, a, b;

    Query() = default;
    Query(int _type, int _a, int _b): type(_type), a(_a), b(_b){}
};

void compress(vector<int>& arr){
    sort(begin(arr), end(arr));
    arr.erase(unique(begin(arr), end(arr)), end(arr));
}

int nodes[(MAXN + MAXQ) * 4 + 5];
void update(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[id] = val;
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, idx, val);
    update(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return INF;
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

vector<Query> queries;
vector<int> values;
int MAXVAL;
int n, q, arr[MAXN + 5];
set<int> pos[MAXN + MAXQ + 5];

int v(const int &val){ return lower_bound(begin(values), end(values), val) - begin(values) + 1; }

void assign(int idx, int val){
    auto curIt = pos[arr[idx]].find(idx);
    if(curIt != pos[arr[idx]].end()){
        int oldPrv = *prev(curIt), oldNxt = *next(curIt);
        if(oldPrv) update(1, 1, MAXVAL + 1, oldPrv, oldNxt);
        pos[arr[idx]].erase(curIt);
    }


    auto nxtIt = pos[val].upper_bound(idx);
    int prvPos = *prev(nxtIt), nxtPos = *nxtIt;
    if(prvPos) update(1, 1, MAXVAL + 1, prvPos, idx);
    update(1, 1, MAXVAL + 1, idx, nxtPos);

    pos[val].insert(idx);
    arr[idx] = val;
}

bool check(int l, int r){
    int minPos = get(1, 1, MAXVAL + 1, l, r);
    return r < minPos;
}

void solve(){
    for(const Query& query: queries){
        if(query.type == 1){
            assign(query.a, query.b);
        }
        else{
            bool ok = check(query.a, query.b);
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        values.push_back(arr[i]);
    }

    for(int qr = 1; qr <= q; ++qr){
        int type;
        cin >> type;

        if(type == 1){
            int k, u;
            cin >> k >> u;

            values.push_back(u);
            queries.emplace_back(type, k, u);
        }
        else{
            int a, b;
            cin >> a >> b;

            queries.emplace_back(type, a, b);
        }
    }

    compress(values);
    MAXVAL = values.size();

    for(int vl = 1; vl <= MAXVAL; ++vl){
        pos[vl].insert(0);
        pos[vl].insert(INF);
    }
    for(int i = n; i >= 1; --i){
        arr[i] = v(arr[i]);
        assign(i, arr[i]);
    }
    for(Query &query: queries){
        if(query.type == 1){
            query.b = v(query.b);
        }
    }

    solve();

    return 0;
}
