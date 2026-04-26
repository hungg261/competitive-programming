/******************************************************************************
Link: https://codeforces.com/contest/607/problem/B
Code: 607B
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-26-10.02.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int res = 0;
    while(!a.empty()){
        n = a.size();
        pair<int, int> LPS = {-1, -1};
        for(int i = 0; i < n; ++i){
            if(i + 1 < n && a[i] == a[i + 1]){
                int L = i, R = i + 1;
                while(a[L] == a[R])
                    --L, ++R;

                ++L; --R;
                LPS = max(LPS, {R - L + 1, L});
            }

            int L = i, R = i;
            while(a[L] == a[R]) --L, ++R;

            ++L; --R;
            LPS = max(LPS, {R - L + 1, L});
        }

        a.erase(begin(a) + LPS.second, begin(a) + LPS.second + LPS.first);
        ++res;
    }

    cout << res << "\n";

    return 0;
}
