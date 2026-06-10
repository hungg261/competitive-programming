/******************************************************************************
Link: https://cses.fi/problemset/task/1742
Code: 1742
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-01-16.24.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

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

    bool operator < (const State& other) const {
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

pair<int, int> shift(int x, int y, char d, int s){
    if(d == 'U') return {x, y + s};
    if(d == 'D') return {x, y - s};
    if(d == 'L') return {x - s, y};
    if(d == 'R') return {x + s, y};
    throw "wtf";
}

vector<pair<char, int>> queries;
int n, total = 0;

int check(int mid){
    vector<array<int, 4>> lines;

    int idx = 0;
    int cx = 0, cy = 0;
    int traveled = 0;

    auto handle = [&](char d, int s, bool check = true){
        if(check && traveled + s >= mid) return false;
        traveled += s;

        int nx, ny;
        tie(nx, ny) = shift(cx, cy, d, s);

//        cerr << cx << ' ' << cy << " | " << nx << ' ' << ny << '\n';

        lines.push_back({cx, cy, nx, ny});
        tie(cx, cy) = {nx, ny};

        return true;
    };

    for(; idx < n; ++idx){
        char d; int s;
        tie(d, s) = queries[idx];

        if(!handle(d, s)) break;
    }

    char d = queries[idx].first;
    handle(d, mid - traveled, false);

    return solve(lines) - idx;
}

int dir(char d){
    if(d == 'U') return 0;
    if(d == 'R') return 1;
    if(d == 'D') return 2;
    if(d == 'L') return 3;
    throw "wtf2";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    int res = -1;
    for(int i = 1; i <= n; ++i){
        char d; int s;
        cin >> d >> s;


        if(i > 1 && res == -1 && (dir(d) + dir(queries.back().first)) % 2 == 0){
            res = total;
        }
        total += s;
        queries.emplace_back(d, s);
    }

    if(res != -1){
        cout << res << '\n';
        return 0;
    }

    int l = 1, r = total;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid) > 0){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';

    return 0;
}
