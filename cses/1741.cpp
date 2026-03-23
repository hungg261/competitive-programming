/******************************************************************************
Link: https://cses.fi/problemset/task/1741
Code: 1741
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-26-17.45.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXVAL = 2e6 + 5;
const int OFFSET = 1e6 + 1;

struct Node{
    int cntMin, minVal, lazy;
    Node(): cntMin(0), minVal(0), lazy(0){}
};

Node nodes[MAXVAL * 4 + 5];

void build(int id, int l, int r){
    nodes[id].minVal = 0;
    nodes[id].cntMin = r - l + 1;

    if(l == r){
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void down(int id){
    int& lz = nodes[id].lazy;

    nodes[id << 1].minVal += lz;
    nodes[id << 1].lazy += lz;

    nodes[id << 1 | 1].minVal += lz;
    nodes[id << 1 | 1].lazy += lz;

    lz = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
        nodes[id].minVal += val;
        nodes[id].lazy += val;
        return;
    }

    down(id);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    nodes[id].minVal = min(nodes[id << 1].minVal, nodes[id << 1 | 1].minVal);

    nodes[id].cntMin = 0;
    if(nodes[id << 1].minVal == nodes[id].minVal) nodes[id].cntMin += nodes[id << 1].cntMin;
    if(nodes[id << 1 | 1].minVal == nodes[id].minVal) nodes[id].cntMin += nodes[id << 1 | 1].cntMin;
}

int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v){
        if(nodes[id].minVal > 0) return r - l + 1;
        return (r - l + 1) - nodes[id].cntMin;
    }

    down(id);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

struct VerticalLine{
    int y1, y2, x, delta;

    bool operator < (const VerticalLine& other) const{
        return this->x < other.x;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1741.INP","r",stdin);
    //freopen("1741.OUT","w",stdout);

    int n;
    cin >> n;

    vector<VerticalLine> cuts;
    for(int i = 1; i <= n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
        }

        cuts.push_back({y1, y2, x1, 1});
        cuts.push_back({y1, y2, x2, -1});
    }
    sort(begin(cuts), end(cuts));

    int ans = 0, last_x = cuts[0].x;
    build(1, 1, MAXVAL);

    for(int i = 0; i < n * 2; ++i){
        ans += get(1, 1, MAXVAL, 1, MAXVAL) * (cuts[i].x - last_x);
        last_x = cuts[i].x;

        update(1, 1, MAXVAL, cuts[i].y1, cuts[i].y2 - 1 , cuts[i].delta);
    }

    cout << ans << '\n';

    return 0;
}
