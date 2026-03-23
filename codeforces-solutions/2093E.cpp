/******************************************************************************
Link: https://codeforces.com/problemset/problem/2093/E
Code: 2093E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-05-18.03.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int MAXN = 2e5;
int arr[MAXN + 5];
int n, k;

bool check(int mid){
    unordered_set<int, chash> S;
    int curmex = 0;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        S.insert(arr[i]);
        while(S.count(curmex)){
            ++curmex;
        }

        if(curmex >= mid){
            S.clear();
            curmex = 0;
            ++cnt;
        }
    }

    return cnt >= k;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    int l = 0, r = n, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << '\n';
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}
