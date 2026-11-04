/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_qg_chuyenghe
Code: nvnamson_qg_chuyenghe
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-03-22.30.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int N, Q;
vector<int> a;

namespace Subtask1 {

int query(int l, int r, int k){
    vector<int> cnt(N + 1, 0);
    int trips = 0;
    int cur = l;
    while(cur <= r){
        ++trips;
        int distinct = 0;
        int i = cur;
        while(i <= r){
            if(cnt[a[i]] == 0){
                if(distinct == k) break;
                ++distinct;
            }
            ++cnt[a[i]];
            ++i;
        }
        for(int j = cur; j < i; ++j) cnt[a[j]] = 0;
        cur = i;
    }
    return trips;
}

void solve(){
    while(Q--){
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        cout << query(l, r, k) << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    a.resize(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    Subtask1::solve();

    return 0;
}
