/******************************************************************************
Link: https://marisaoj.com/problem/259
Code: 259
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-08-11.46.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int arr[MAXN + 5], n, q;
vector<tuple<int, int, int, int>> queries;

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
        int _l = l / range, _r = r / range;

        if(_l > _r) continue;

        diff2[range][st][_r + 1] -= val;
        diff2[range][st][_l] += val;

        diff1[range][st][_r + 1] -= (_l - 1) * val;
        diff1[range][st][_l] += (_l - 1) * val;
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int qr = 1; qr <= q; ++qr){
        int l, r, range, val;
        cin >> l >> r >> range;
        val = 1;

        queries.emplace_back(l, r, range, val);
    }

    solve();

    return 0;
}
