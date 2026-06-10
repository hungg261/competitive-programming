/******************************************************************************
Link: https://cses.fi/problemset/task/3191
Code: 3191
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-06-21.15.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct XorBasis{
    static const int MAXLG = 30;
    int basis[MAXLG];

    XorBasis(){
        memset(basis, 0, sizeof basis);
    }

    void add(int x){
        for(int b = MAXLG - 1; b >= 0; --b){
            if(!(x >> b & 1)) continue;

            if(basis[b] == 0){
                basis[b] = x;
                return;
            }

            x ^= basis[b];
        }
    }

    bool in(int x){
        for(int b = MAXLG - 1; b >= 0; --b){
            if(x >> b & 1){
                if(basis[b] == 0)
                    return false;
                x ^= basis[b];
            }
        }
        return true;
    }

    int getMax(){
        int res = 0;
        for(int b = MAXLG - 1; b >= 0; --b){
            res = max(res, res ^ basis[b]);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    XorBasis basis;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        basis.add(cur);
    }

    cout << basis.getMax() << "\n";

    return 0;
}
