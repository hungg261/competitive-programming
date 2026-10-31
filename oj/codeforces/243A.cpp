/******************************************************************************
Link: https://codeforces.com/problemset/problem/243/A
Code: 243A
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-10.28.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    set<int> cur;
    set<int> all;
    for(int i = 0; i < n; ++i){
        set<int> nxt = {arr[i]};
        for(int val: cur){
            nxt.insert(val | arr[i]);
        }

        cur = nxt;
        for(int x: cur)
            all.insert(x);
    }

    cout << (int)all.size() << "\n";

    return 0;
}
