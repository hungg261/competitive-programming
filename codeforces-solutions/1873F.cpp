/******************************************************************************
Link: https://codeforces.com/problemset/problem/1873/F
Code: 1873F
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-22.51.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, k;
int arr[MAXN + 5], h[MAXN + 5];
int pre[MAXN + 5];

int longest[MAXN + 5];
void compute(){
    for(int i = 1; i <= n;){
        int j = i;
        for(; j < n; ++j){
            if(h[j] % h[j + 1] != 0){
                break;
            }
        }

        for(int k = i; k <= j; ++k){
            longest[k] = j - k + 1;
        }

        i = j + 1;
    }
}

bool check(int mid){
    for(int i = 1; i <= n; ++i){
        if(longest[i] >= mid){
            if(pre[i + mid - 1] - pre[i - 1] <= k){
                return true;
            }
        }
    }

    return false;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    for(int i = 1; i <= n; ++i) cin >> h[i];

    compute();

    int l = 1, r = n, res = 0;
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
