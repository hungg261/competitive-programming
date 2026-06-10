/******************************************************************************
Link: https://codeforces.com/problemset/problem/2060/B
Code: 2060B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-17.09.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> card_idx(n * m);
    vector<int> cnt(n, 0);
    int rounds = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int cd;
            cin >> cd;

            card_idx[cd] = i;
        }
    }

    vector<int> res;
    for(int cd = 0; cd < n * m; ++cd){
        if(cd % n == 0) ++rounds;

        int cidx = card_idx[cd];
        int cur = ++cnt[cidx];
        res.push_back(cidx + 1);

        if(cur != rounds){
            cout << "-1\n";
            return;
        }
        if(res.size() == n) break;
    }

    int idx = 0;
    for(int cd = 0; cd < n * m; ++cd){
        if(res[idx] - 1 != card_idx[cd]){
            cout << "-1\n";
            return;
        }

        idx = (idx + 1) % n;
    }

    for(int ele: res){
        cout << ele << ' ';
    }
    cout << '\n';
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
