/******************************************************************************
Link: https://www.codechef.com/problems/KSIZEGCD
Code: KSIZEGCD
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-10.48.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct State{
    int g, l, r;
};

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<State> v;
    vector<int> res(n + 1, -1);
    for(int i = 1; i <= n; ++i){
        vector<State> u = {{a[i], i, i}};
        for(const State &st: v){
            int g = __gcd(st.g, a[i]);

            if(g == u.back().g){
                u.back().l = st.l;
                u.back().r = i;
            }
            else{
                u.push_back({g, st.l, i});
            }
        }

        v = u;
//        cerr << i << ":\n";
        for(const State &st: v){
//            cerr << "\t-> " << st.g << " " << st.l << " " << st.r << endl;
//            for(int len = i - st.r + 1; len <= i - st.l + 1; ++len){
//                res[len] = max(res[len], st.g);
//            }

            int len = i - st.l + 1;
            res[len] = max(res[len], st.g);
        }
    }

    for(int i = n - 1; i >= 1; --i){
        res[i] = max(res[i], res[i + 1]);
    }

    for(int k = 1; k <= n; ++k){
        cout << res[k] << " ";
    }
    cout << "\n";
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
