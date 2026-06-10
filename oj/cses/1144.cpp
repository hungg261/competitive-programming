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

    int get(int l, int r){
        return get(r) - get(l - 1);
    }
};

int convert(int value, const vector<int>& temp){
    return lower_bound(begin(temp), end(temp), value) - begin(temp) + 1;
}

struct Query{
    char type;
    int first, second;
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1), values;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        values.push_back(p[i]);
    }

    vector<Query> queries(q + 1);
    for(int i = 1; i <= q; ++i){
        cin >> queries[i].type >> queries[i].first >> queries[i].second;
        if(queries[i].type == '!') values.push_back(queries[i].second);
    }
//
    sort(begin(values), end(values));
    FenwickTree fwt(values.size() + 1);
    for(int i = 1; i <= n; ++i) fwt.update(convert(p[i], values), 1);

    for(int i = 1; i <= q; ++i){
        if(queries[i].type == '?'){
            int L = lower_bound(begin(values), end(values), queries[i].first) - begin(values) + 1;
            int R = upper_bound(begin(values), end(values), queries[i].second) - begin(values);

            int res = fwt.get(L, R);
            cout << res << '\n';
        }
        else{
            fwt.update(convert(p[queries[i].first], values), -1);
            fwt.update(convert(queries[i].second, values), 1);
            p[queries[i].first] = queries[i].second;
        }
    }

    return 0;
}
