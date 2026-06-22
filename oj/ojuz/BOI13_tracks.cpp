/******************************************************************************
Link: https://oj.uz/problem/view/BOI13_tracks
Code: BOI13_tracks
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-22-16.30.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 4000;
int H, W, dp[2][MAX];

int lab[MAX * MAX / 2 + 5];
int comb[MAX * MAX / 2 + 5];

void init(){
    for(int u = 1; u <= H * W / 2 + 3; ++u){
        lab[u] = -1;
        comb[u] = 0;
    }
}

int find(int v){
    return lab[v] < 0 ? v : lab[v] = find(lab[v]);
}

inline int unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(lab[a] > lab[b]) swap(a, b);

        lab[a] += lab[b];
        comb[a] = comb[b];
        lab[b] = a;
    }
    return a;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> H >> W;
    init();

    string row;
    int Counter = 0;
    for(int i = 0; i < H; ++i){
        int b = i & 1;
        cin >> row;

        memset(dp[b], 0, sizeof dp[b]);
        for(int j = 0; j < W; ++j){
            if(row[j] == '.') continue;

            int top = dp[b ^ 1][j];
            int left = j > 0 ? dp[b][j - 1] : 0;

            if(top && left) dp[b][j] = unite(top, left);
            else if(top || left) dp[b][j] = max(top, left);
            else dp[b][j] = ++Counter;

            int &contrib = comb[dp[b][j]];
            if(contrib == 0) contrib = row[j];
            else if(contrib != -1) contrib = contrib != row[j] ? -1 : contrib;
        }
    }

    int res = 0;
    for(int u = 1; u <= Counter; ++u){
        if(lab[u] < 0){
            if(comb[u] < 0) res += 2;
            else ++res;
        }
    }

    cout << res << "\n";

    return 0;
}
