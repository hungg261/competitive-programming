/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_thaotac
Code: hsg_hcm_v2_25_thaotac
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-10-14.34.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> a;

namespace Subtask1{

void solve(){
    while(Q--){
        int L, R;
        cin >> L >> R;

        int res = 0;
        for(int i = L; i <= R; ++i){
            for(int j = i + 1; j <= R; ++j){
                res += a[i] % a[j] + a[j] % a[i];
            }
        }

        cout << res << "\n";
    }
}

}

namespace Subtask2{

void solve(){
    vector<array<int, 11>> pre(N + 1);
    pre[0].fill(0);

    for(int i = 1; i <= N; ++i){
        pre[i] = pre[i - 1];
        ++pre[i][a[i]];
    }

    while(Q--){
        int L, R;
        cin >> L >> R;

        array<int, 11> freq;
        long long res = 0;
        for(int j = 1; j <= 10; ++j){
            freq[j] = pre[R][j] - pre[L - 1][j];
            for(int i = 1; i < j; ++i){
                res += 1LL * (j % i + i) * freq[i] * freq[j];
            }
        }

        cout << res << "\n";
    }
}

}

namespace Subtask3{

void solve(){
    vector<vector<long long>> pre(N + 1, vector<long long>(N + 1));
    for(int i = 1; i <= N; ++i){
        pre[i][0] = 0;
        for(int j = 1; j <= N; ++j){
            pre[i][j] = pre[i][j - 1] + (a[j] % a[i]);
        }
    }

    while(Q--){
        int L, R;
        cin >> L >> R;

        long long res = 0;
        for(int i = L; i <= R; ++i){
            res += pre[i][R] - pre[i][L - 1];
        }

        cout << res << "\n";
    }
}

}

namespace Subtask4{

void solve(){
    int maxVal = *max_element(begin(a) + 1, end(a));
    vector<vector<long long>> pre(maxVal + 1, vector<long long>(N + 1));
    vector<vector<int>> freq(N + 1, vector<int>(maxVal + 1, 0));

    vector<int> temp = a;
    sort(begin(temp) + 1, end(temp));
    temp.erase(unique(begin(temp) + 1, end(temp)), end(temp));

    int sz = temp.size();
    for(int i = 1; i < sz; ++i){
        int u = temp[i];

        pre[u][0] = 0;
        for(int j = 1; j <= N; ++j){
            pre[u][j] = pre[u][j - 1] + (a[j] % u);
        }
    }

    for(int i = 1; i <= N; ++i){
        freq[i] = freq[i - 1];
        ++freq[i][a[i]];
    }

    while(Q--){
        int L, R;
        cin >> L >> R;

        long long res = 0;
        for(int u = 1; u <= maxVal; ++u){
            res += 1LL * (pre[u][R] - pre[u][L - 1]) * (freq[R][u] - freq[L - 1][u]);
        }

        cout << res << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("THAOTAC.INP","r",stdin);
    freopen("THAOTAC.OUT","w",stdout);

    cin >> N >> Q;

    a.resize(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }

    int maxVal = *max_element(begin(a) + 1, end(a));
    if(N <= 100 && Q <= 100 && maxVal <= 100000) Subtask1::solve();
    else if(N <= 50000 && Q <= 100000 && maxVal <= 10) Subtask2::solve();
    else if(N <= 1000 && Q <= 100000 && maxVal <= 100000) Subtask3::solve();
    else Subtask4::solve();

    return 0;
}
