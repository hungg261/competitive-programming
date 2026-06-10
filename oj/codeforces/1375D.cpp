/******************************************************************************
Link: https://codeforces.com/problemset/problem/1375/D
Code: 1375D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-04-09.59.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), mark(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] <= n) ++mark[a[i]];
    }

    auto find_mex = [&mark, &n](){
        for(int v = 0; v <= n; ++v)
            if(!mark[v]) return v;
        return -1;
    };

    auto assign = [&mark, &n](int& x, int y){
        if(x <= n) --mark[x];
        if(y <= n) ++mark[y];
        x = y;
    };

    vector<int> op;
    while(!is_sorted(begin(a), end(a))){
        int mex = find_mex();
        if(mex < n){
            assign(a[mex], mex);
            op.push_back(mex);
        }
        else{
            for(int i = 0; i < n; ++i){
                if(a[i] != i){
                    assign(a[i], mex);
                    op.push_back(i);
                    break;
                }
            }
        }
    }

    cout << (int)op.size() << "\n";
    for(int idx: op) cout << idx + 1 << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
