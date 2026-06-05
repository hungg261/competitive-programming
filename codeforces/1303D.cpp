/******************************************************************************
Link: https://codeforces.com/problemset/problem/1303/D
Code: 1303D
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-18.57.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long target; int n;
    cin >> target >> n;

    long long sum = 0;
    multiset<int> ms;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        sum += cur;
        ms.insert(cur);
    }

    if(sum < target){
        cout << "-1\n";
        return;
    }

    int res = 0;
    for(long long b = 1; b <= target; b <<= 1){
        if((target & b) == b){
            auto lb = ms.upper_bound(b);
            long long cursum = 0;
            for(auto it = ms.begin(); it != lb; ++it){
                cursum += *it;
                if(cursum >= b) break;
            }

            if(cursum < b){
                auto it = ms.lower_bound(b);
                int value = *it;

                while(value > b){
                    ms.insert(value >>= 1);
                    ++res;
                }

                ms.erase(it);
            }
            else{
                for(auto it = prev(lb); ; --it){
                    target -= *it;
                }
            }
        }
    }

    cout << res << "\n";
}

/*
1
183 8
1 8 32 4 32 1 64 64
*/

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
