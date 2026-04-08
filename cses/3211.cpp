/******************************************************************************
Link: https://cses.fi/problemset/task/3211
Code: 3211
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-06-23.08.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct XorBasis{
    static const int MAXLG = 30;
    int basis[MAXLG];
    int _size;

    XorBasis(){
        _size = 0;
        memset(basis, 0, sizeof basis);
    }

    void add(int x){
        for(int b = MAXLG - 1; b >= 0; --b){
            if(!(x >> b & 1)) continue;

            if(basis[b] == 0){
                basis[b] = x;
                _size++;
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

    int size(){
        return _size;
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

    cout << (1 << basis.size()) << "\n";

    return 0;
}
