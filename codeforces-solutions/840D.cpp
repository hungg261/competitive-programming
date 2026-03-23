/******************************************************************************
Link: https://codeforces.com/contest/840/problem/D
Code: 840D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-27-14.37.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct WaveletTree{
    int lo, hi;
    vector<int> pref;
    WaveletTree *l, *r;

    WaveletTree(int *from, int *to, int L, int R){
        lo = L; hi = R;
        l = r = nullptr;
        if(from >= to) return;

        int mid = (lo + hi) >> 1;
        auto f = [&mid](int x){ return x <= mid; };

        pref.push_back(0);
        for(auto it = from; it != to; ++it){
            pref.push_back(pref.back() + f(*it));
        }

        if(lo == hi) return;

        auto pivot = stable_partition(from, to, f);
        l = new WaveletTree(from, pivot, lo, mid);
        r = new WaveletTree(pivot, to, mid + 1, hi);
    }

    int kth(int lq, int rq, int k){
        if(lq > rq) return -1;
        if(lo == hi) return lo;

        int inLeft = pref[rq] - pref[lq - 1];
        if(k <= inLeft) return l->kth(pref[lq - 1] + 1, pref[rq], k);
        else return r->kth(lq - pref[lq - 1], rq - pref[rq], k - inLeft);
    }

    int cnt_leq(int lq, int rq, int x){
        if(lq > rq) return 0;
        if(lo > x) return 0;
        if(hi <= x) return rq - lq + 1;

        return l->cnt_leq(pref[lq - 1] + 1, pref[rq], x) +
                r->cnt_leq(lq - pref[lq - 1], rq - pref[rq], x);
    }

    int cnt_eq(int lq, int rq, int x){
        if(lq > rq || hi < x || x < lo) return 0;
        if(lo == hi) return rq - lq + 1;

        int mid = (lo + hi) >> 1;
        if(x <= mid) return l->cnt_eq(pref[lq - 1] + 1, pref[rq], x);
        else return r->cnt_eq(lq - pref[lq - 1], rq - pref[rq], x);
    }

    void find_freq_more(int lq, int rq, int cnt, int& res){
        if(lq > rq) return;
        if(rq - lq + 1 <= cnt) return;
        if(lo == hi){
            res = min(res, lo);
            return;
        }

        l->find_freq_more(pref[lq - 1] + 1, pref[rq], cnt, res);
        r->find_freq_more(lq - pref[lq - 1], rq - pref[rq], cnt, res);
    }
};

const int MAXN = 3e5;
int n, q, arr[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    WaveletTree wlt(arr + 1, arr + n + 1, 1, n);

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        int res = n + 1;
        wlt.find_freq_more(l, r, (r - l + 1) / k, res);

        cout << (res == n + 1 ? -1 : res) << '\n';
    }

    return 0;
}
