/******************************************************************************
Link: https://codeforces.com/gym/105675/problem/6
Code: Gym_1056756
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-08-10.25.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e5;
int n, k, a[MAXN + 5];

namespace Brute{

int res = LLONG_MIN;
vector<int> pos;
void gen(int idx){
    if((int)pos.size() > k - 1) return;
    else if(idx > n - 1){
        if((int)pos.size() != k - 1) return;
        pos.push_back(n);

        int id = 1;
        int mx = LLONG_MIN, mn = LLONG_MAX;
        for(int i = 0; i < k; ++i){
            int sum = 0;
            for(; id <= pos[i]; ++id){
                sum += a[id];
            }

            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        pos.pop_back();

        res = max(res, mx - mn);
        return;
    }

    pos.push_back(idx);
    gen(idx + 1);
    pos.pop_back();

    gen(idx + 1);
}

void solve(){
    gen(1);

    cout << res << endl;
}

}

namespace Solve{

int pre[MAXN + 5];
long long subsolve(){
    pre[0] = 0;
    for(int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + a[i];

    vector<int> minPre(n + 2), minSuf(n + 2);
    minPre[0] = LLONG_MAX; minSuf[n + 1] = LLONG_MAX;

    for(int i = 1; i <= n; ++i) minPre[i] = min(minPre[i - 1], a[i]);
    for(int i = n; i >= 1; --i) minSuf[i] = min(minSuf[i + 1], a[i]);

    long long res = LLONG_MIN;
    int prefix = 0;
    for(int j = 1; j <= n; ++j){
        int i = max(1LL, j - (n - k + 1) + 1);
        prefix += a[j];
        int sum = pre[j] - pre[i - 1];

        if(k > 2) res = max(res, sum - min(minPre[i - 1], minSuf[j + 1]));
        else if(j < n) res = max(res, abs(prefix - (pre[n] - prefix)));
    }

    return res;
}

void solve(){
    long long res = subsolve();
    reverse(a + 1, a + n + 1);
    res = max(res, subsolve());

    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    Solve::solve();

    return 0;
}
