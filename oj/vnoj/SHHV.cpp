/******************************************************************************
Link: https://oj.vnoi.info/problem/SHHV
Code: SHHV
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-26-07.52.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 12;
int n, k, a[MAXN], fact[MAXN + 1];

namespace Compute{

void make(){
    fact[0] = 1;
    for(int i = 1; i <= n; ++i){
        fact[i] = fact[i - 1] * i;
    }
}

}

namespace Unrank{

void solve(){
    vector<int> ans;
    int mask = 0;
    for(int pos = 1; pos <= n; ++pos){
        for(int i = 1; i <= n; ++i){
            if(mask >> i & 1) continue;

            int cnt = fact[n - pos];
            if(k > cnt) k -= cnt;
            else{
                ans.push_back(i);
                mask |= 1 << i;
                break;
            }
        }
    }

    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}

}

namespace Rank{

int temp[MAXN];

void solve(){
    int mask = 0;

    for(int i = 0; i < n; ++i)
        temp[i] = a[i];
    sort(temp, temp + n);

    int res = 0;
    for(int pos = 0; pos < n; ++pos){
        int idx = lower_bound(temp, temp + n, a[pos]) - temp;
        for(int i = 0; i < idx; ++i){
            if(mask >> i & 1) continue;
            res += fact[n - pos - 1];
        }

        mask |= 1 << idx;
    }

    cout << res + 1 << "\n";
}

}

void solve(){
    Compute::make();
    Rank::solve();
    Unrank::solve();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string line;
    getline(cin, line);
    stringstream ss(line);

    n = 0;
    int token;
    while(ss >> token)
        a[n++] = token;

    cin >> k;

    solve();

    return 0;
}
