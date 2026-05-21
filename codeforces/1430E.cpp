/******************************************************************************
Link: https://codeforces.com/contest/1430/problem/E
Code: 1430E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-21-09.31.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int res = 0;

void op(int i){
    swap(s[i], s[i + 1]);
    ++res;
}

void solve(){
    string original = s;

    int i = 0, j = n - 1;
    while(i < j){
        if(s[i] != s[j]){
            int closet_i = i, closet_j = j;
            while(closet_i < j && s[closet_i] != original[j]) ++closet_i;
            while(closet_j > i && s[closet_j] != original[i]) --closet_j;

//            cerr << closet_i << " " << closet_j << endl;

            for(int x = closet_i; x > i; --x) op(x - 1);

            if(closet_i > closet_j) ++closet_j;
            for(int x = closet_j; x < j; ++x) op(x);
        }

//        cerr << s << "\n";

        ++i; --j;
    }

    cerr << s << "\n";
    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    solve();

    return 0;
}
