/******************************************************************************
Link: https://vjudge.net/contest/734806#problem/C
Code: C
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-07-13.02.28
*******************************************************************************/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 10000, MAXVAL = 30005;
struct Node{
    int covered = 0, filled = 0;
};

Node nodes[MAXVAL * 4 + 5];

void pull(int id, int l, int r, int val){
    if(nodes[id].covered > 0) nodes[id].filled = r - l + 1;
    else if(l != r) nodes[id].filled = nodes[id << 1].filled + nodes[id << 1 | 1].filled;
    else nodes[id].filled = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].covered += val;
        pull(id, l, r, val);
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    pull(id, l, r, val);
}

struct Segment{
    int x, y1, y2;
    int type;

    bool operator < (const Segment& other){
        return (this->x < other.x) || (this->x == other.x && this->type < other.type);
    }
};
vector<Segment> states;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        states.push_back({x1, y1 + 1, y2 + 1, 1});
        states.push_back({x2, y1 + 1, y2 + 1, -1});
    }
    sort(begin(states), end(states));

    long long ans = 0;
    for(int i = 0; i < n * 2 - 1; ++i){
        const Segment& seg = states[i];
        update(1, 1, MAXVAL, seg.y1, seg.y2 - 1, seg.type);
        ans += 1LL * (states[i + 1].x - seg.x) * nodes[1].filled;
    }

    cout << ans << '\n';

    return 0;
}
