/******************************************************************************
Link: https://vjudge.net/contest/734806#problem/A
Code: A
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-07-00.39.45
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Point{
    int x, y;
    int id;

    bool operator < (const Point& other){
        return x < other.x || (x == other.x && y < other.y);
    }
};

struct cmp{
    bool operator()(const Point& A, const Point& B){
        return A.y < B.y || (A.y == B.y && A.x < B.x);
    }
};

int sqdist(const Point& A, const Point& B){
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

double dist(const Point& A, const Point& B){ return sqdist(A, B); }

const int MAXN = 50000, INF = 1e9;
Point arr[MAXN + 5];
set<Point, cmp> T;
int n;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].x >> arr[i].y;
        arr[i].id = i;
    }
    sort(arr + 1, arr + n + 1);

    int sq_d = sqdist(arr[1], arr[2]);
    int id1 = arr[1].id, id2 = arr[2].id;

    for(int i = 1; i <= n; ++i){
        int x = arr[i].x, y = arr[i].y;
        int id = arr[i].id;

        int d = (int)sqrt(sq_d) + 1;
        while(!T.empty()){
            Point p = *T.begin();
            if(x - p.x > d) T.erase(p);
            else break;
        }

        auto it_low = T.lower_bound({0, y - d, 0}),
            it_high = T.upper_bound({0, y + d, 0});

        for(auto it = it_low; it != it_high; ++it){
            int new_d = sqdist(arr[i], *it);
            if(new_d < sq_d){
                sq_d = new_d;
                id1 = it->id;
                id2 = id;
            }
        }

        T.insert(arr[i]);
    }

    if(id1 > id2) swap(id1, id2);
    cout << id1 - 1 << ' ' << id2 - 1 << ' ';
    cout << fixed << setprecision(6) << sqrt(sq_d) << '\n';

    return 0;
}
