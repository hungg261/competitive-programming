/******************************************************************************
Link: https://acmicpc.net/problem/28434
Code: 28434
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-24-10.36.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 250'000;
int a[MAXN + 5], b[MAXN + 5], n;

int f(int l, int r){
    if(l > r) return 0;
    else if(l == r){
        return a[l] == b[r];
    }

    int mid = (l + r) >> 1;

    vector<int> pre_min1 = {INF}, pre_max1 = {-INF};
    vector<int> pre_min2 = {INF}, pre_max2 = {-INF};
    vector<int> pre_min = {0}, pre_max = {0}, pre_both = {0};
    for(int i = mid + 1; i <= r; ++i){
        pre_min1.push_back(min(pre_min1.back(), a[i]));
        pre_max1.push_back(max(pre_max1.back(), a[i]));

        pre_min2.push_back(min(pre_min2.back(), b[i]));
        pre_max2.push_back(max(pre_max2.back(), b[i]));

        bool eqmin = pre_min1.back() == pre_min2.back();
        bool eqmax = pre_max1.back() == pre_max2.back();
        pre_min.push_back(pre_min.back() + eqmin);
        pre_max.push_back(pre_max.back() + eqmax);
        pre_both.push_back(pre_both.back() + (eqmin && eqmax));
    }

    int sz = r - mid;
    int contrib = 0;

    int lmin1, rmin1, lmin2, rmin2, lmax1, rmax1, lmax2, rmax2;
    lmin1 = rmin1 = lmin2 = rmin2 = lmax1 = rmax1 = lmax2 = rmax2 = 1;

    int pmin1, pmax1, pmin2, pmax2;
    pmin1 = pmax1 = pmin2 = pmax2 = 0;

    int min1, max1, min2, max2;
    min1 = min2 = INF, max1 = max2 = -INF;
    for(int i = mid; i >= l; --i){
        min1 = min(min1, a[i]);
        max1 = max(max1, a[i]);
        min2 = min(min2, b[i]);
        max2 = max(max2, b[i]);

        while(pmin1 < sz && pre_min1[pmin1 + 1] >= min1) ++pmin1;
        while(pmin2 < sz && pre_min2[pmin2 + 1] >= min2) ++pmin2;
        while(pmax1 < sz && pre_max1[pmax1 + 1] <= max1) ++pmax1;
        while(pmax2 < sz && pre_max2[pmax2 + 1] <= max2) ++pmax2;

        while(lmin1 <= sz && pre_min1[lmin1] > min2) ++lmin1;
        while(rmin1 <= sz && pre_min1[rmin1] >= min2) ++rmin1;

        while(lmin2 <= sz && pre_min2[lmin2] > min1) ++lmin2;
        while(rmin2 <= sz && pre_min2[rmin2] >= min1) ++rmin2;

        while(lmax1 <= sz && pre_max1[lmax1] < max2) ++lmax1;
        while(rmax1 <= sz && pre_max1[rmax1] <= max2) ++rmax1;

        while(lmax2 <= sz && pre_max2[lmax2] < max1) ++lmax2;
        while(rmax2 <= sz && pre_max2[rmax2] <= max1) ++rmax2;

        vector<int> pos = {0, pmin1, pmin2, pmax1, pmax2, sz};
        sort(begin(pos), end(pos));

        for(int j = 0; j + 1 < (int)pos.size(); ++j){
            int u = pos[j] + 1, v = pos[j + 1];
            if(u > v) continue;

            int cmin1 = (u <= pmin1), cmin2 = (u <= pmin2);
            int cmax1 = (u <= pmax1), cmax2 = (u <= pmax2);

            bool need_both_min = false, need_both_max = false;

            if(cmin1 && cmin2){
                if(min1 != min2) continue;
            }
            else if(cmin1 && !cmin2){
                u = max(u, lmin2);
                v = min(v, rmin2 - 1);
            }
            else if(!cmin1 && cmin2){
                u = max(u, lmin1);
                v = min(v, rmin1 - 1);
            }
            else need_both_min = true;

            if(cmax1 && cmax2){
                if(max1 != max2) continue;
            }
            else if(cmax1 && !cmax2){
                u = max(u, lmax2);
                v = min(v, rmax2 - 1);
            }
            else if(!cmax1 && cmax2){
                u = max(u, lmax1);
                v = min(v, rmax1 - 1);
            }
            else need_both_max = true;

            if(u > v) continue;

            if(need_both_min && need_both_max){
                contrib += pre_both[v] - pre_both[u - 1];
            }
            else if(need_both_min){
                contrib += pre_min[v] - pre_min[u - 1];
            }
            else if(need_both_max){
                contrib += pre_max[v] - pre_max[u - 1];
            }
            else contrib += v - u + 1;
        }
    }

    return f(l, mid) + f(mid + 1, r) + contrib;
}

void solve(){
    cout << f(1, n) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    solve();

    return 0;
}
