/******************************************************************************
Link: https://marisaoj.com/problem/364
Code: 364
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-17-16.01.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

namespace Stress{
// failed

vector<int> arr;
int cost(int i, int j){
    return (arr[i] - arr[j]) * (arr[i] - arr[j]);
}

bool check(int a, int b, int c, int d){
    return cost(a, c) + cost(b, d) <= cost(a, d) + cost(b, c);
}

void stress(){
    srand(time(NULL));
    while(true){
        int n = rand() % 10 + 1;
        arr = vector<int>(n);
        for(int i = 0; i < n; ++i)
            arr[i] = rand() % 10 + 1;

        if(![&](){
            for(int a = 0; a < n; ++a){
                for(int b = a; b < n; ++b){
                    for(int c = b; c < n; ++c){
                        for(int d = c; d < n; ++d){
                            if(!check(a, b, c, d)) return false;
                        }
                    }
                }
            }
            return true;
           }()){
                cerr << n << "\n";
                for(int i = 0; i < n; ++i)
                    cerr << arr[i] << " ";
                cerr << endl;
                break;
           }
           else cerr << "CORRECT\n";
    }
}

}

struct Line{
    int m, c;

    Line(int _m = 0, int _c = LLONG_MIN): m(_m), c(_c){}

    int eval(int x){
        return m * x + c;
    }

    bool operator < (const Line& other) const {
        return m < other.m || (m < other.m && c < other.c);
    }

    friend istream& operator >> (istream& is, Line& l){
        return is >> l.m >> l.c;
    }
    friend ostream& operator << (ostream& os, Line& l){
        return os << l.m << l.c;
    }
};

const int MAXN = 1e4, MAXK = 100;
int n, k, a[MAXN + 5];
vector<int> xs;
inline int v(int x){ return lower_bound(begin(xs), end(xs), x) - begin(xs); }

Line nodes[MAXN * 4 + 5];

void build(int id = 1, int l = 0, int r = (int)xs.size() - 1){
    nodes[id] = Line();
    if(l == r) return;

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void add_line(Line f, int id = 1, int l = 0, int r = (int)xs.size() - 1){
    int mid = (l + r) >> 1;
    Line& g = nodes[id];
    if(f.eval(xs[mid]) > g.eval(xs[mid])) swap(g, f);

    if(l == r) return;

    if(f.eval(xs[l]) > g.eval(xs[l])) add_line(f, id << 1, l, mid);
    else add_line(f, id << 1 | 1, mid + 1, r);
}

int get(int idx, int id = 1, int l = 0, int r = (int)xs.size() - 1){
    int cur = nodes[id].eval(xs[idx]);
    if(l == r) return cur;

    int mid = (l + r) >> 1;
    if(idx <= mid) cur = max(cur, get(idx, id << 1, l, mid));
    else cur = max(cur, get(idx, id << 1 | 1, mid + 1, r));
    return cur;
}

int dp[MAXN + 5][MAXK + 5];

namespace Brute{

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int j = 1; j <= k; ++j){
        for(int i = 1; i <= n; ++i){
            for(int z = 1; z <= i; ++z){
                dp[i][j] = min(dp[i][j], dp[z - 1][j - 1] + (a[i] - a[z]) * (a[i] - a[z]));
            }
        }
    }

    for(int j = 1; j <= k; ++j){
        for(int i = 1; i <= n; ++i){
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << dp[n][k] << "\n";
}

}

namespace Solve{

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int j = 1; j <= k; ++j){
        build();
        for(int i = 1; i <= n; ++i){
            add_line(Line(-(-2 * a[i]), -(a[i] * a[i] + dp[i - 1][j - 1])));
            dp[i][j] = a[i] * a[i] + -get(v(a[i]));
        }
    }

//    for(int j = 1; j <= k; ++j){
//        for(int i = 1; i <= n; ++i){
//            cerr << dp[i][j] << " ";
//        }
//        cerr << endl;
//    }

    cout << dp[n][k] << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        xs.push_back(a[i]);
    }
    sort(begin(xs), end(xs));

//    Brute::solve();
    Solve::solve();

    return 0;
}
