#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int find_furthest_leq(int target){
        int l = 1, r = n - 1, res = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(get(mid) <= target){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if(res == -1) throw "idk";
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> x(n + 1);
    FenwickTree fwt(n + 1);

    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        fwt.update(i, 1);
    }

    for(int i = 1; i <= n; ++i){
        int p; cin >> p;

        int idx = fwt.find_furthest_leq(p);
        cout << x[idx] << ' ';

        fwt.update(idx + 1, -1);
    }

    return 0;
}
