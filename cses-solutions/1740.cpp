/******************************************************************************
Link: https://cses.fi/problemset/task/1740
Code: 1740
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-26-15.02.15
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree(int sz = 0): n(sz){
        BIT.resize(sz + 1, 0);
    }

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

int priority(int type){
    if(type == 1) return 1;
    if(type == 0) return 2;
    if(type == -1) return 3;
    throw "wtf";
}

struct State{
    int x, y1, y2;
    int type;

    State(int _x, int _y1, int _y2, int _type): x(_x), y1(_y1), y2(_y2), type(_type){}

    bool operator<(const State& other){
        return x < other.x || (x == other.x && priority(type) < priority(other.type));
    }
};

int solve(const vector<array<int, 4>>& segments){
    vector<int> values;
    vector<State> states;

    for(const auto& seg: segments){
        int x1 = seg[0], y1 = seg[1], x2 = seg[2], y2 = seg[3];

        if(y1 == y2){
            if(x1 > x2) swap(x1, x2);
            states.emplace_back(x1, y1, y1, 1);
            states.emplace_back(x2, y1, y1, -1);

            values.push_back(x1);
            values.push_back(x2);
            values.push_back(y1);
        }
        else{
            if(y1 > y2) swap(y1, y2);
            states.emplace_back(x1, y1, y2, 0);

            values.push_back(x1);
            values.push_back(y1);
            values.push_back(y2);
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto v = [&](int value){
        return lower_bound(values.begin(), values.end(), value) - values.begin() + 1;
    };

    for(auto& st: states){
        st.x = v(st.x);
        st.y1 = v(st.y1);
        st.y2 = v(st.y2);
    }

    sort(states.begin(), states.end());

    FenwickTree fwt(values.size() + 5);
    int ans = 0;

    for(const State& cur: states){
        if(cur.type == 0){
            ans += fwt.get(cur.y1, cur.y2);
        }
        else{
            fwt.update(cur.y1, cur.type);
        }
    }

    return ans;
}

signed main(){
    int n;
    cin >> n;

    vector<array<int, 4>> arr;
    for(int i = 1; i <= n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        arr.push_back({x1, y1, x2, y2});
    }

    cout << solve(arr) << '\n';
    return 0;
}
