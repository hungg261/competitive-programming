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

void trau(){
    string original = s;

    int i = 0, j = n - 1;
    while(i < j){
        if(s[i] != s[j]){
            int closet_i = i, closet_j = j;
            while(closet_i < j && s[closet_i] != original[j]) ++closet_i;
            while(closet_j > i && s[closet_j] != original[i]) --closet_j;

            for(int x = closet_i; x > i; --x) op(x - 1);

            if(closet_i > closet_j) ++closet_j;
            for(int x = closet_j; x < j; ++x) op(x);
        }

        ++i; --j;
    }

    cerr << s << "\n";
    cout << res << "\n";
}

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

void solve(){
    set<int> pos[26];
    for(int i = 0; i < n; ++i)
        pos[s[i] - 'a'].insert(i + 1);

    vector<int> T(n, -1);
    for(int i = 0, j = n - 1; i <= j; ++i, --j){
        int ci = s[i] - 'a', cj = s[j] - 'a';
        auto itL = pos[cj].begin(), itR = prev(pos[ci].end());
        T[i] = *itL; T[j] = *itR;

        pos[cj].erase(T[i]);
        pos[ci].erase(T[j]);
    }

    FenwickTree fwt(n);
    long long res = 0;
    for(int i = n - 1; i >= 0; --i){
        res += fwt.get(T[i] - 1);
        fwt.update(T[i], 1);
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    solve();

    return 0;
}
