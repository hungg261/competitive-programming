/******************************************************************************
Link: https://codeforces.com/gym/104239/problem/D
Code: Gym_104239D
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-01-10.57.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6, MOD = 139;
int n, m, q;
int a[MAXN + 5], b[MAXN + 5];

namespace Subtask1{

int k[MAXN + 5];
void solve(){
    for(int i = 1; i + m + q - 1 <= n; ++i){
        bool ok = true;
        for(int j = q; j < m + q; ++j){
            if((b[i + j] - a[j - q + 1] + MOD) % MOD != b[i + j % q]){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << i << "\n";
            return;
        }
    }

    cout << "-1\n";
}

}

namespace Solve{

void solve(){
    vector<int> arr;
    for(int i = 1; i <= q; ++i) arr.push_back(a[i]);
    for(int i = 1; i + q <= m; ++i){
        arr.push_back((a[i + q] - a[i] + MOD) % MOD);
    }
    arr.push_back(-1);
    for(int i = 1; i + q <= n; ++i){
        arr.push_back((b[i + q] - b[i] + MOD) % MOD);
    }

    int sz = arr.size();
    vector<int> pi(sz);
    pi[0] = 0;

    int len = m - q;
    for(int i = 1; i < sz; ++i){
        int j = pi[i - 1];
        while(j > 0 && arr[i] != arr[j]){
            j = pi[j - 1];
        }

        if(arr[i] == arr[j]) ++j;
        pi[i] = j;

        if(j == m){
            int start_pos = i - 2 * m + 1;
            cout << start_pos << "\n";
            return;
        }
    }

    cout << "-1\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    Solve::solve();

    return 0;
}
