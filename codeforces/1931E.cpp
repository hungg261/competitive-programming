/******************************************************************************
Link: https://codeforces.com/problemset/problem/1931/E
Code: 1931E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-18.15.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    ++m;

    vector<int> num(n);
    int total = 0;

    auto dsum = [](int x){
        int res = 0;
        while(x > 0){
            res++;
            x /= 10;
        }
        return res;
    };
    for(int i = 0; i < n; ++i){
        cin >> num[i];
        total += dsum(num[i]);
    }

    auto cntLast = [](int x){
        int res = 0;
        while(x % 10 == 0){
            x /= 10;
            ++res;
        }
        return res;
    };

    sort(begin(num), end(num), [&cntLast](auto& x, auto& y){
            return cntLast(x) > cntLast(y);
         });

    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            total -= cntLast(num[i]);
        }
    }

    cout << (total >= m ? "Sasha" : "Anna") << '\n';
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
