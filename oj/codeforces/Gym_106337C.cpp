/******************************************************************************
Link: https://codeforces.com/gym/106337/problem/C
Code: Gym_106337C
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-22-19.59.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e9, MOD = 1e9 + 7;
const int MAXN = 2e5, MAXM = 2e5;
struct Rect{
    int x, y;

    Rect(int _x = -1, int _y = -1): x(_x), y(_y){}

    void input(){
        cin >> x >> y;
    }

    void disable(){ x = -1; }
    bool is_disabled() const { return x == -1; }

    bool contain(const Rect& other) const {
        return other.x <= x && other.y <= y;
    }

    bool operator < (const Rect& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    friend ostream& operator << (ostream& os, const Rect& rect){
        return os << rect.x << " " << rect.y;
    }
};

int n, m;
vector<Rect> arr;

namespace Utils{

void normalize(){
    sort(begin(arr) + 1, end(arr));

    vector<Rect> clean_arr;
    clean_arr.emplace_back();

    for(int i = 1; i <= n; ++i){
        while(clean_arr.size() > 1 && arr[i].contain(clean_arr.back())){
            clean_arr.pop_back();
        }
        if(clean_arr.size() > 1 && clean_arr.back().contain(arr[i])){
            continue;
        }
        clean_arr.push_back(arr[i]);
    }

    arr = clean_arr;
    n = arr.size() - 1;

    arr[0] = Rect(0, INF);
    arr.emplace_back(INF, 0);
}

int powmod(int a, int b, int mod = MOD){
    a %= mod;
    int res = 1 % mod;

    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

}

namespace Subtask8{

int dp[MAXN + 5];
void solve(){
    dp[0] = 1;
    int left = m * m;
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];
        for(int j = 1; j <= i; ++j){
            dp[i] += dp[j - 1] * (arr[j].x - arr[j - 1].x) % MOD * (arr[i].y - arr[i + 1].y) % MOD;
            dp[i] %= MOD;
        }

        left -= (arr[i].x - arr[i - 1].x) * arr[i].y;
    }

    cout << (dp[n] * Utils::powmod(2, left)) % MOD << "\n";
}

}

namespace Solve{

int dp[MAXN + 5];
void solve(){
    dp[0] = 1;
    int left = m * m;

    int pre = 0;
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];
        pre = (pre + dp[i - 1] * arr[i].x % MOD - dp[i - 1] * arr[i - 1].x % MOD) % MOD;

        int contrib = pre;
        contrib = contrib * (arr[i].y - arr[i + 1].y) % MOD;

        dp[i] = (dp[i] + contrib) % MOD;

        left -= (arr[i].x - arr[i - 1].x) * arr[i].y;
    }

    cout << (dp[n] * Utils::powmod(2, left) % MOD + MOD) % MOD << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    arr.resize(n + 1);

    for(int i = 1; i <= n; ++i){
        arr[i].input();
    }
    Utils::normalize();

    Solve::solve();

    return 0;
}
