/******************************************************************************
Link: https://codeforces.com/problemset/problem/453/B
Code: 453B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-14.48.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int PRIME = 17, MAX = 59;
const int primes[PRIME] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int f[MAX + 1];

void compute(){
    f[0] = 0;
    for(int p = 0; p < PRIME; ++p){
        for(int j = primes[p]; j <= MAX; j += primes[p]){
            f[j] |= 1 << p;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    compute();

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << PRIME, INF));
    vector<vector<pair<int, int>>> trace(n + 1, vector<pair<int, int>>(1 << PRIME, {-1, -1}));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= MAX; ++j){
            int x = (~f[j]) & ((1 << PRIME) - 1);

            for(int sub = x; ; sub = (sub - 1) & x){
                int& nxt = dp[i][sub | f[j]];
                int newCost = dp[i - 1][sub] + abs(arr[i] - j);

                if(newCost < nxt){
                    nxt = newCost;
                    trace[i][sub | f[j]] = {sub, j};
                }

                if(sub == 0) break;
            }
        }
    }

    int bmask = min_element(begin(dp[n]), end(dp[n])) - begin(dp[n]);
    vector<int> res;
    for(int i = n; i >= 1; --i){
        int cur;
        tie(bmask, cur) = trace[i][bmask];
        res.push_back(cur);
    }

    reverse(begin(res), end(res));
    for(int ele: res) cout << ele << ' ';
    cout << '\n';

    return 0;
}
