/******************************************************************************
Link: https://codeforces.com/contest/2036/problem/E
Code: 2036E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-18.52.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr;

struct Condition{
    int r;
    char o;
    int c;

    void input(){
        cin >> r >> o >> c;
    }

    bool operator < (const Condition& other) const{
        return r < other.r;
    }
};

const int LIM = 2e9;
pair<int, int> unite(int l1, int r1, int l2, int r2){
    return {max(l1, l2), min(r1, r2)};
}

int find_low(int c, int target){
    int l = 1, r = n, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid][c] >= target){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

int find_high(int c, int target){
    int l = 1, r = n, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid][c] <= target){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

void solve(){
    int cd;
    cin >> cd;

    vector<Condition> queries(cd);
    for(Condition& cond: queries) cond.input();
    sort(begin(queries), end(queries));

    int l = 0, r = LIM;
    int L = 1, R = n;
    for(int i = 0; i < cd; ++i){
        if(i == 0 || queries[i].r == queries[i - 1].r){
            if(queries[i].o == '<') tie(l, r) = unite(l, r, 0, queries[i].c - 1);
            else tie(l, r) = unite(l, r, queries[i].c + 1, LIM);

            if(l > r){
                cout << "-1\n";
                return;
            }
        }
        else{
            int lo = find_low(queries[i - 1].r, l);
            int hi = find_high(queries[i - 1].r, r);


            if(lo == -1 || hi == -1){
                cout << "-1\n";
                return;
            }

            L = max(L, lo);
            R = min(R, hi);

            l = 0, r = LIM;
            if(queries[i].o == '<') tie(l, r) = unite(l, r, 0, queries[i].c - 1);
            else tie(l, r) = unite(l, r, queries[i].c + 1, LIM);
        }
    }
    int lo = find_low(queries.back().r, l);
    int hi = find_high(queries.back().r, r);
    L = max(L, lo);
    R = min(R, hi);

    if(lo == -1 || hi == -1 || L > R) cout << "-1\n";
    else cout << L << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> m >> q;
    arr.resize(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> arr[i][j];
            arr[i][j] |= arr[i - 1][j];
        }
    }

    while(q--){
        solve();
    }

    return 0;
}
