/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_bn_v2_25_lock
Code: hsg_bn_v2_25_lock
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-17-08.21.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("lock.INP","r",stdin);
    freopen("lock.OUT","w",stdout);

    int n, q;
    cin >> n >> q;

    map<int, int> mp;
    for(int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;

        mp[r + 1]--;
        mp[l]++;
    }

    long long pre = 0;
    int res = 0;
    int last = 1;
    for(const pair<int, int>& p: mp){
        if(pre == 0) res += p.first - last;
        last = p.first;

        pre += p.second;
        pre %= 3;
    }
    if(last <= n && pre == 0) res += n - last + 1;

    cout << res << "\n";

    return 0;
}
