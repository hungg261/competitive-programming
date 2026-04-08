/******************************************************************************
Link: https://oj.vnoi.info/problem/demen_08_ezpoly
Code: demen_08_ezpoly
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-07-20.48.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

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

const int MAXN = 1e5;
int arr[MAXN + 5], n, q;
vector<tuple<int, int, int, int>> queries;

namespace Sub1{

void solve(){
    vector<int> res(n + 1, 0);
    for(const auto& tp: queries){
        int l, r, range, val;
        tie(l, r, range, val) = tp;

        assert(l == r);

        int idx = l;
        res[idx] += val;
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << " ";
    }
    cout << "\n";
}

}

namespace Sub2{

//int nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];
//
//void apply(int id, int l, int r, int lz){
//    nodes[id] += (l + r) * (r - l + 1) / 2 * lz;
//    lazy[id] += lz;
//}
//
//void down(int id, int l, int r){
//    int& lz = lazy[id];
//    if(lz == 0) return;
//
//    int mid = (l + r) >> 1;
//    apply(id << 1, l, mid, lz);
//    apply(id << 1 | 1, mid + 1, r, lz);
//
//    lz = 0;
//}
//
//void update(int id, int l, int r, int u, int v, int val){
//    if(v < l || r < u) return;
//    if(u <= l && r <= v){
//        apply(id, l, r, val);
//        return;
//    }
//
//    down(id, l, r);
//
//    int mid = (l + r) >> 1;
//    update(id << 1, l, mid, u, v, val);
//    update(id << 1 | 1, mid + 1, r, u, v, val);
//    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
//}
//
//int get(int id, int l, int r, int idx){
//    if(r < idx || idx < l) return 0;
//    if(l == r) return nodes[id];
//
//    down(id, l, r);
//
//    int mid = (l + r) >> 1;
//    return get(id << 1, l, mid, idx) + get(id << 1, mid + 1, r, idx);
//}

void solve(){
    FenwickTree diff1(n + 1), diff2(n + 1);
    for(const auto& tp: queries){
        int l, r, range, val;
        tie(l, r, range, val) = tp;

        assert(range == 1);

        diff1.update(r + 1, -val);
        diff1.update(l, val);

        diff2.update(r + 1, - (l - 1) * val);
        diff2.update(l, (l - 1) * val);
    }

    for(int i = 1; i <= n; ++i){
        cout << (i * diff1.get(i) - diff2.get(i)) << " ";
    }
    cout << "\n";
}

}

namespace Sub3{

int SQRT;
void solve(){
    SQRT = sqrt(n);

    vector<int> res(n, 0);
    vector<vector<vector<int>>> diff1(SQRT + 1, vector<vector<int>>(SQRT + 1));
    vector<vector<vector<int>>> diff2(SQRT + 1, vector<vector<int>>(SQRT + 1));
    for(int s = 1; s <= SQRT; ++s){
        for(int i = 0; i < s; ++i){
            diff1[s][i].resize(n / s + 2, 0);
            diff2[s][i].resize(n / s + 2, 0);
        }
    }

    for(const auto& tp: queries){
        int l, r, range, val;
        tie(l, r, range, val) = tp;
        --l; --r;


        if(range > SQRT){
            int c = 0;
            for(int i = l; i <= r; i += range){
                res[i] += val * (c + 1);
                ++c;
            }
            continue;
        }

        int st = l % range;
        int _l = (l + range - 1) / range, _r = r / range;

        if(_l > _r) continue;

        diff2[range][st][_r + 1] -= val;
        diff2[range][st][_l] += val;

        diff1[range][st][_r + 1] -= (_l - 1) * val;
        diff1[range][st][_l] += (_l - 1) * val;

//        cerr << l << " " << r << " " << range << " | " << st << " " << _l << " " << _r << "\n";
    }

    for(int s = 1; s <= SQRT; ++s){
        for(int st = 0; st < s; ++st){
            int prefix1 = 0, prefix2 = 0;
            for(int i = 0; i < n / s + 1; ++i){
                prefix1 += diff1[s][st][i];
                prefix2 += diff2[s][st][i];

                int idx = st + i * s;
                res[idx] += i * prefix2 - prefix1;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << res[i] << " ";
    }

    cout << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    bool is_sub1 = true, is_sub2 = true;
    for(int qr = 1; qr <= q; ++qr){
        int l, r, range, val;
        cin >> l >> r >> range;
        val = 1;

        queries.emplace_back(l, r, range, val);
        is_sub1 &= l == r;
        is_sub2 &= range == 1;
    }

//    if(is_sub1) Sub1::solve();
//    else if(is_sub2) Sub2::solve();

    Sub3::solve();

    return 0;
}
/*
5 2
1 3 1 1
4 5 1 2

5 4
1 5 1 1
1 5 2 3
1 4 3 2
2 5 3 4

6 6 9 8 22
*/
