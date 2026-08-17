/******************************************************************************
Link: https://www.spoj.com/problems/XXXXXXXX/
Code: XXXXXXXX
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-17-09.36.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4, MAXBLOCK = 2150;
struct Query{
    int l, r, t, id;

    bool operator < (const Query& other) const {
        if(l / MAXBLOCK != other.l / MAXBLOCK) return l / MAXBLOCK < other.l / MAXBLOCK;
        if(r / MAXBLOCK != other.r / MAXBLOCK) return r / MAXBLOCK < other.r / MAXBLOCK;
        return t < other.t;
    }
};
struct Update{
    int pos, old_val, new_val;
};

int n, q, a[MAXN + 5];
vector<Query> queries;
vector<Update> updates;
vector<int> values;
vector<int> freq;

inline int v(int x){ return lower_bound(begin(values), end(values), x) - begin(values); }

int curL = 1, curR = 0, curT = 0;
long long cur = 0;

void add(int pos){
    if(freq[a[pos]]++ == 0)
        cur += values[a[pos]];
}
void pop(int pos){
    if(--freq[a[pos]] == 0)
        cur -= values[a[pos]];
}
void do_update(int t_idx, int is_forward){
    int pos = updates[t_idx].pos;
    int val = is_forward ? updates[t_idx].new_val : updates[t_idx].old_val;

    if(curL <= pos && pos <= curR){
        pop(pos);
        a[pos] = val;
        add(pos);
    }
    else a[pos] = val;
}

int query_cnt = 0;
void solve(){
    sort(begin(queries), end(queries));
    vector<long long> res(query_cnt + 1, -1);
    for(const Query& qr: queries){
        while(curT < qr.t) do_update(++curT, true);
        while(curT > qr.t) do_update(curT--, false);
        while(curL > qr.l) add(--curL);
        while(curR < qr.r) add(++curR);
        while(curL < qr.l) pop(curL++);
        while(curR > qr.r) pop(curR--);

        res[qr.id] = cur;
    }

    for(int i = 1; i <= query_cnt; ++i){
        cout << res[i] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }

    cin >> q;

    vector<tuple<char, int, int>> store;
    store.emplace_back();
    for(int i = 1; i <= q; ++i){
        char type; int x, y;
        cin >> type >> x >> y;

        if(type == 'U'){
            values.push_back(y);
        }

        store.emplace_back(type, x, y);
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));
    freq.resize(values.size() + 1, 0);

    vector<int> backup(n + 1);
    for(int i = 1; i <= n; ++i)
        backup[i] = a[i] = v(a[i]);

    updates.push_back({0, 0, 0});
    for(int i = 1; i <= q; ++i){
        char type; int x, y;
        tie(type, x, y) = store[i];

        if(type == 'U'){
            updates.push_back({x, backup[x], backup[x] = v(y)});
        }
        else if(type == 'Q'){
            queries.push_back({x, y, (int)updates.size() - 1, ++query_cnt});
        }
    }

    solve();

    return 0;
}
