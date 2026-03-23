/******************************************************************************
Link: https://codeforces.com/problemset/problem/12/D
Code: 12D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-03-15.01.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, MAXVAL = 1e9 + 5;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] = max(BIT[i], val);
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res = max(res, BIT[i]);
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

struct Lady{
    int B, I, R, id;

    void input(int i){
        cin >> B >> I >> R;
        id = i;
    }

    bool operator < (const Lady& other) const{
        if(B != other.B) return B < other.B;
        if(I != other.I) return I < other.I;
        return R < other.R;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<Lady> Ladies(n);
    vector<int> values;

    for(int i = 0; i < n; ++i){
        cin >> Ladies[i].B;
    }
    for(int i = 0; i < n; ++i){
        cin >> Ladies[i].I;
        values.push_back(Ladies[i].I);
    }
    for(int i = 0; i < n; ++i){
        cin >> Ladies[i].R;
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    int MAX = values.size();
    for(Lady& ld: Ladies){
        ld.B = MAXVAL - ld.B;

        ld.I = lower_bound(begin(values), end(values), ld.I) - begin(values);
        ld.I = MAX - ld.I;
    }

    sort(begin(Ladies), end(Ladies));
    FenwickTree fwt(MAX + 5);
    int j = 0;

    int res = 0;
    for(int i = 0; i < n; ++i){
        while(j < n && Ladies[j].B < Ladies[i].B){
            fwt.update(Ladies[j].I, Ladies[j].R);
            ++j;
        }

        if(Ladies[i].R < fwt.get(Ladies[i].I - 1)){
            ++res;
        }
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
