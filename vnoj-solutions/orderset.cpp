/******************************************************************************
Link: https://vjudge.net/contest/732386#problem/B
Code: B
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-04-13.44.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
struct Query{
    char type;
    int x;

    Query() = default;
    Query(char _type): type(_type), x(-1){}
    Query(char _type, int _x): type(_type), x(_x){}
};

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz): n(sz){
        BIT.resize(sz + 1, 0);
    }

    void update(int idx, int val){
        for(int i = idx; i <= n; i += i & -i) BIT[i] += val;
    }

    int get(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= i & -i) res += BIT[i];
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 2e5;
vector<int> values;
Query queries[MAXN + 5];
int q;

int v(int value){
    return lower_bound(begin(values), end(values), value) - begin(values) + 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("B.INP","r",stdin);
    //freopen("B.OUT","w",stdout);
    cin >> q;
    for(int i = 1; i <= q; ++i){
        char type;
        cin >> type;

        if(type == 'I'){
            int x; cin >> x;
            queries[i] = Query(type, x);
            values.push_back(x);
        }
        else if(type == 'D'){
            int x; cin >> x;
            queries[i] = Query(type, x);
            values.push_back(x);
        }
        else if(type == 'K'){
            int k; cin >> k;
            queries[i] = Query(type, k);
        }
        else if(type == 'C'){
            int x; cin >> x;
            queries[i] = Query(type, x);
            values.push_back(x);
        }
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    FenwickTree fwt(values.size());
    for(int i = 1; i <= q; ++i){
        char type = queries[i].type;
        int x = queries[i].x;

        if(type == 'I'){
            int val_x = v(x);
            if(fwt.get(val_x, val_x) == 0) fwt.update(v(x), 1);
        }
        else if(type == 'D'){
            int val_x = v(x);
            if(fwt.get(val_x, val_x) > 0) fwt.update(val_x, -1);
        }
        else if(type == 'K'){
            int l = 1, r = values.size(), res = -1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(fwt.get(mid) >= x){
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            if(res == -1) cout << "invalid\n";
            else cout << values[res - 1] << '\n';
        }
        else if(type == 'C'){
            cout << fwt.get(v(x) - 1) << '\n';
        }
    }

    return 0;
}
