/******************************************************************************
Link: https://oj.vnoi.info/problem/sqrt_d
Code: sqrt_d
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-07-19.11.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int BLOCKSIZE = 1000;
const int MAXN = 1e6;
struct Point{
    int x, y, idx;

    void input(int i){
        cin >> x >> y;
        idx = i;
    }

    int dist(const Point& other){
        return abs(x - other.x) + abs(y - other.y);
    }

    bool operator < (const Point& other){
        int blockX = (x - 1) / BLOCKSIZE + 1;
        int blockY = (other.x - 1) / BLOCKSIZE + 1;

        if(blockX == blockY){
            return (blockX & 1) ? (y < other.y) : (y > other.y);
        }

        return blockX < blockY;
    }
};

int n;
Point points[MAXN + 5];

void solve(){
    sort(points + 1, points + n + 1);
    for(int i = 1; i <= n; ++i){
        cout << points[i].idx << ' ';
    }
    cout << '\n';

    auto cnt_matdist = [&](){
        int ans = 0;
        for(int i = 1; i < n; ++i){
            ans += points[i].dist(points[i + 1]);
        }
        ans += points[n].dist(points[1]);

        return ans;
    };

    cerr << cnt_matdist() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("sqrt_d.INP","r",stdin);
    //freopen("sqrt_d.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        points[i].input(i);
    }

    solve();

    return 0;
}
