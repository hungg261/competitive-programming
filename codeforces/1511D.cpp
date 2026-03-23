/******************************************************************************
Link: https://codeforces.com/contest/1511/problem/D
Code: 1511D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-18-14.30.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    int used = 0;
    auto put = [&used](int c){
        cout << (char)(c + 'a');
        ++used;
    };

    while(used < n){
        for(int a = 0; a < k; ++a){
            put(a);
            if(used >= n) return 0;

            for(int b = a + 1; b < k; ++b){
                put(a);
                if(used >= n) return 0;

                put(b);
                if(used >= n) return 0;
            }
        }
    }

    return 0;
}
