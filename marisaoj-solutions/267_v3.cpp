/******************************************************************************
Link: https://marisaoj.com/problem/267
Code: 267
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-10-20.27.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

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
int pre[MAXN + 5];
int n, q;

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
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + table[i][0].input();
    }

    compute();

    while(q--){
        int l, r;
        cin >> l >> r;

        int mn, mx;
        tie(mn, mx) = get(l, r).get();

        int sum = pre[r] - pre[l - 1],
            csum = (mn + mx) * (mx - mn + 1) / 2;

        cout << (mx - mn == r - l && sum == csum ? "YES\n" : "NO\n");
    }

    return 0;
}
