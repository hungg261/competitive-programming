/******************************************************************************
Link: https://codeforces.com/problemset/problem/1936/A
Code: 1936A
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-30-19.39.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

char query(int a, int b, int c, int d){
    cout << "? " << a << " " << b << " " << c << " " << d << endl;

    char o;
    cin >> o;

    return o;
}

char query(int a, int b){
    return query(a, a, b, b);
}

void solve(){
    int n;
    cin >> n;

    int res_i = 0, res_j = -1;
    for(int i = 1; i < n; ++i){
        if(query(i, res_i) == '>'){
            res_i = i;
        }
    }

    vector<int> ids = {0};
    for(int i = 0; i < n; ++i){
        if(i == res_i) continue;

        int top = ids.back();
        switch(query(i, res_i, top, res_i)){
            case '>': {
                ids = {i};
                break;
            }
            case '=': {
                ids.push_back(i);
                break;
            }
        }
    }

    for(int id: ids){
        if(res_j == -1 || query(id, res_j) == '<')
            res_j = id;
    }

    cout << "! " << res_i << " " << res_j << endl;
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
