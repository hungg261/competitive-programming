/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_quyhoach
Code: nvnamson_quyhoach
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-08.36.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXK = 10;
int n, k;

struct Rect{
    int x1, y1, x2, y2;
    friend istream &operator >> (istream &is, Rect &rect){
        return is >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
    }
};

vector<Rect> rects;

namespace Subtask1{

const int LIM = 300;
int diff[LIM + 5][LIM + 5];

void solve(){
    int maxX = 0, maxY = 0;

    for(const Rect &r: rects){
        maxX = max(maxX, r.x2);
        maxY = max(maxY, r.y2);
    }

    for(const Rect &r: rects){
        diff[r.x1][r.y1]++;
        diff[r.x2][r.y1]--;
        diff[r.x1][r.y2]--;
        diff[r.x2][r.y2]++;
    }

    long long ans = 0;

    for(int x = 0; x < maxX; ++x){
        for(int y = 0; y < maxY; ++y){
            if(x > 0) diff[x][y] += diff[x - 1][y];
            if(y > 0) diff[x][y] += diff[x][y - 1];
            if(x > 0 && y > 0) diff[x][y] -= diff[x - 1][y - 1];
            if(diff[x][y] >= k) ans++;
        }
    }

    cout << ans << "\n";
}

}

namespace Subtask2{

const int MAXVAL = 2 * MAXN;
int ys[MAXVAL + 5];
int m;

struct Node{
    int covered = 0, filled = 0;
};

Node nodes[MAXVAL * 4 + 5];

void pull(int id, int l, int r){
    if(nodes[id].covered > 0) nodes[id].filled = ys[r + 1] - ys[l];
    else if(l != r) nodes[id].filled = nodes[id << 1].filled + nodes[id << 1 | 1].filled;
    else nodes[id].filled = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].covered += val;
        pull(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    pull(id, l, r);
}

struct Segment{
    int x, y1, y2;
    int type;

    bool operator < (const Segment& other) const {
        return (this->x < other.x) || (this->x == other.x && this->type < other.type);
    }
};

vector<Segment> states;

void solve(){
    for(const Rect &r: rects){
        ys[m++] = r.y1;
        ys[m++] = r.y2;
    }
    sort(ys, ys + m);
    m = int(unique(ys, ys + m) - ys);

    auto getY = [&](int y){
        return int(lower_bound(ys, ys + m, y) - ys);
    };

    states.reserve(2 * n);
    for(const Rect &r: rects){
        states.push_back({r.x1, getY(r.y1), getY(r.y2) - 1, 1});
        states.push_back({r.x2, getY(r.y1), getY(r.y2) - 1, -1});
    }
    sort(begin(states), end(states));

    long long ans = 0;
    int cnt = (int)states.size();

    for(int i = 0; i < cnt - 1; ++i){
        const Segment &seg = states[i];
        update(1, 0, m - 2, seg.y1, seg.y2, seg.type);
        ans += 1LL * (states[i + 1].x - seg.x) * nodes[1].filled;
    }

    cout << ans << "\n";
}

}

namespace Subtask3{

vector<int> ys;
vector<int> diff;

struct Event{
    int x, l, r, type;

    bool operator < (const Event &other) const {
        return x < other.x;
    }
};

vector<Event> events;

void solve(){
    ys.reserve(2 * n);
    for(const Rect &r: rects){
        ys.push_back(r.y1);
        ys.push_back(r.y2);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int m = (int)ys.size();

    auto getY = [&](int y){
        return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
    };

    events.reserve(2 * n);
    for(const Rect &r: rects){
        int l = getY(r.y1);
        int r_idx = getY(r.y2);
        events.push_back({r.x1, l, r_idx, 1});
        events.push_back({r.x2, l, r_idx, -1});
    }
    sort(events.begin(), events.end());

    diff.assign(m + 1, 0);

    long long ans = 0;
    int cnt = (int)events.size();

    for(int i = 0; i < cnt - 1; ++i){
        const Event &e = events[i];
        diff[e.l] += e.type;
        diff[e.r] -= e.type;

        long long filled = 0;
        int cur = 0;
        for(int j = 0; j < m - 1; ++j){
            cur += diff[j];
            if(cur >= k){
                filled += ys[j + 1] - ys[j];
            }
        }

        ans += 1LL * (events[i + 1].x - e.x) * filled;
    }

    cout << ans << "\n";
}

}

namespace Subtask4{

const int MAXVAL = 2 * MAXN;
int ys[MAXVAL + 5];
int m;

struct Node{
    int cnt, len[MAXK + 1];

    Node(){
        cnt = 0;
        memset(len, 0, sizeof len);
    }
};

Node nodes[MAXVAL * 4 + 5];

void pull(int id, int l, int r){
    memset(nodes[id].len, 0, sizeof nodes[id].len);
    int cnt = nodes[id].cnt;

    if(cnt >= k){
        nodes[id].len[k] = ys[r + 1] - ys[l];
    }
    else{
        if(l == r){
            nodes[id].len[cnt] = ys[r + 1] - ys[l];
        }
        else{
            for(int i = 0; i <= k; ++i){
                nodes[id].len[min(k, i + cnt)] += nodes[id << 1].len[i] + nodes[id << 1 | 1].len[i];
            }
        }
    }
}

void build(int id, int l, int r){
    if(l == r){
        nodes[id].len[0] = ys[r + 1] - ys[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pull(id, l, r);
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].cnt += val;
        pull(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    pull(id, l, r);
}

struct Segment{
    int x, y1, y2;
    int type;

    bool operator < (const Segment& other) const {
        return (this->x < other.x) || (this->x == other.x && this->type < other.type);
    }
};

vector<Segment> states;

void solve(){
    for(const Rect &r: rects){
        ys[m++] = r.y1;
        ys[m++] = r.y2;
    }
    sort(ys, ys + m);
    m = unique(ys, ys + m) - ys;

    auto getY = [&](int y){
        return int(lower_bound(ys, ys + m, y) - ys);
    };

    states.reserve(2 * n);
    for(const Rect &r: rects){
        states.push_back({r.x1, getY(r.y1), getY(r.y2) - 1, 1});
        states.push_back({r.x2, getY(r.y1), getY(r.y2) - 1, -1});
    }
    sort(begin(states), end(states));

    long long ans = 0;
    int cnt = (int)states.size();
    build(1, 0, m - 2);

    for(int i = 0; i < cnt - 1; ++i){
        const Segment &seg = states[i];
        update(1, 0, m - 2, seg.y1, seg.y2, seg.type);
        ans += 1LL * (states[i + 1].x - seg.x) * nodes[1].len[k];
    }

    cout << ans << "\n";
}

}



signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    rects.resize(n);

    int maxCoord = 0;

    for(int i = 0; i < n; ++i){
        cin >> rects[i];
        maxCoord = max(maxCoord, rects[i].x1);
        maxCoord = max(maxCoord, rects[i].y1);
        maxCoord = max(maxCoord, rects[i].x2);
        maxCoord = max(maxCoord, rects[i].y2);
    }

    if(n <= 300 && maxCoord <= 300) Subtask1::solve();
    else if(k == 1) Subtask2::solve();
    else if(n <= 3000) Subtask3::solve();
    else Subtask4::solve();

    return 0;
}
