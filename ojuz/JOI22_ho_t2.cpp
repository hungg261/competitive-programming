/******************************************************************************
Link: https://oj.uz/problem/view/JOI22_ho_t2
Code: JOI22_ho_t2
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-31-11.25.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e5;
int a[MAXN + 5], b[MAXN + 5], n, m;

bool check(int mid){
    int left = n * m;
    vector<int> need(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        if(a[i] >= b[i]){
            int weeks = (mid + a[i] - 1) / a[i];
            if(weeks > m){
                need[i] += (mid - a[i] * m + b[i] - 1) / b[i];
                left -= m;
            }
            else left -= weeks;
        }
        else need[i] += (mid + b[i] - 1) / b[i];
    }

    for(int i = 1; i <= n; ++i){
        left -= need[i];
        if(left < 0) return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }

    int l = 0, r = 1e18, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << "\n";

    return 0;
}
