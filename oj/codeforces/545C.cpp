#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Tree{
    int x, h;

    bool operator < (const Tree& other){
        return this->x < other.x;
    }

    bool together(const Tree& other){
        return other.x + other.h < x - h;
    }

    bool touchL(const Tree& other){
        return x - h <= other.x && other.x <= x;
    }

    bool touchR(const Tree& other){
        return x <= other.x && other.x <= x + h;
    }

    void input(){
        cin >> x >> h;
    }
};

const int MAXN = 1e5;
Tree T[MAXN + 5];
int n;

bool fallR[MAXN + 5];
void solve(){
    int last = -1e18;
    int ans = 1;

    for(int i = 1; i <= n - 1; ++i){
        if(T[i].x - T[i].h > last){
            last = T[i].x;
            ++ans;
        }
        else if(T[i].x + T[i].h < T[i + 1].x){
            last = T[i].x + T[i].h;
            ++ans;
        }
        else last = T[i].x;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        T[i].input();
    }
    sort(T + 1, T + n + 1);

    solve();

    return 0;
}
