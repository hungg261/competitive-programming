/******************************************************************************
Link: https://marisaoj.com/problem/267
Code: 267
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-10-20.09.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
    int mn, mx;

    Node() = default;
    Node(int _mn, int _mx): mn(_mn), mx(_mx){}

    int input(){
        cin >> mn;
        return mx = mn;
    }

    Node operator + (const Node& other){
        return Node(
                min(mn, other.mn),
                max(mx, other.mx)
                    );
    }

    pair<int, int> get(){
        return {mn, mx};
    }
};

const int MAXN = 1e5, MAXLG = __lg(MAXN);
Node table[MAXN + 5][MAXLG + 5];
uint64_t cpre[MAXN + 5], pre[MAXN + 5];
int n, q;
map<int, uint64_t> mp;

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
        }
    }
}

Node get(int l, int r){
    int bit = __lg(r - l + 1);
    return table[l][bit] + table[r - (1 << bit) + 1][bit];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cpre[i] = cpre[i - 1] ^ (mp[i] = rng());
    for(int i = 1; i <= n; ++i){
        int cur = table[i][0].input();
        pre[i] = pre[i - 1] ^ mp[cur];
    }

    compute();

    while(q--){
        int l, r;
        cin >> l >> r;

        int mn, mx;
        tie(mn, mx) = get(l, r).get();

        uint64_t XOR = pre[r] ^ pre[l - 1],
            cXOR = cpre[mx] ^ cpre[mn - 1];

        cout << (mx - mn == r - l && XOR == cXOR ? "YES\n" : "NO\n");
    }

    return 0;
}
