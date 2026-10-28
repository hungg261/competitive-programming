/******************************************************************************
Link: https://codeforces.com/problemset/problem/1234/D
Code: 1234D
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-15.29.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

FenwickTree fwt[26];
string s;


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int n = s.size();
    s = "#" + s;

    for(int c = 0; c < 26; ++c){
        fwt[c] = FenwickTree(n);
        for(int i = 1; i <= n; ++i){
            if(s[i] - 'a' == c){
                fwt[c].update(i, 1);
            }
        }
    }

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int pos; char c;
            cin >> pos >> c;

            fwt[s[pos] - 'a'].update(pos, -1);
            s[pos] = c;
            fwt[s[pos] - 'a'].update(pos, 1);
        }
        else{
            int l, r;
            cin >> l >> r;

            int res = 0;
            for(int c = 0; c < 26; ++c){
                if(fwt[c].get(l, r) > 0) ++res;
            }

            cout << res << "\n";
        }
    }

    return 0;
}
