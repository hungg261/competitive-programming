/******************************************************************************
Link: https://codeforces.com/contest/1207/problem/F
Code: 1207F
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-25-18.34.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, MAXSQRT = sqrt(MAXN) + 1;
int arr[MAXN + 5];
int tab[MAXSQRT + 5][MAXSQRT + 5];

void update(int i, int x){
    arr[i] += x;
    for(int a = 1; a <= MAXSQRT; ++a){
        tab[a][i % a] += x;
    }
}

long long get(int x, int y){
    long long res = 0;
    if(x > MAXSQRT){
        for(int i = y; i <= MAXN; i += x){
            res += arr[i];
        }
    }
    else{
        res = tab[x][y];
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;

    while(q--){
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1) update(x, y);
        else cout << get(x, y) << "\n";
    }

    return 0;
}
