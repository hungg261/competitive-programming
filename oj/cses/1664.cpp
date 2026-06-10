/******************************************************************************
Link: https://cses.fi/problemset/task/1664
Code: 1664
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-22-15.17.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Movie{
    int l, r;
    int id;

    void input(int i){
        id = i;
        cin >> l >> r;
    }

    bool operator < (const Movie& other){
        return r < other.r;
    }
};

const int MAXN = 2e5, MAXQ = 2e5, MAXVAL = 1e6;
const int MAXK = __lg(MAXN) + 1;
int n, q;
int table[MAXN + 5][MAXK + 5];

Movie arr[MAXN + 5];
vector<pair<int, int>> events[MAXVAL + 5];

struct pqCmp{
    bool operator () (const int& x, const int& y){
        return arr[y] < arr[x];
    }
};

int nxt[MAXVAL + 5];

void compute(){
    priority_queue<int, vector<int>, pqCmp> pq;
    for(int e = MAXVAL; e >= 1; --e){
        for(const pair<int, int>& p: events[e]){
            if(p.first == 0) pq.push(p.second);
        }

        nxt[e] = pq.empty() ? n + 1 : pq.top();
    }

    for(int i = 1; i <= n; ++i){
        table[i][0] = nxt[arr[i].r];
    }
    table[n + 1][0] = n + 1;

    for(int j = 1; j <= MAXK; ++j){
        for(int i = 1; i <= n + 1; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

void query(int a, int b){
    int idx = nxt[a];
    if(idx > n || arr[idx].r > b){
        cout << "0\n";
        return;
    }

    int res = 1;
    for(int bit = MAXK; bit >= 0; --bit){
        int p = table[idx][bit];
        if(p <= n && arr[p].r <= b){
            idx = p;
            res += 1 << bit;
        }
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1664.INP","r",stdin);
    //freopen("1664.OUT","w",stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        arr[i].input(i);

        events[arr[i].l].emplace_back(0, i);
        events[arr[i].r].emplace_back(1, i);
    }

    compute();

    while(q--){
        int a, b;
        cin >> a >> b;

        query(a, b);
    }

    return 0;
}
