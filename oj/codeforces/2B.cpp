#include<bits/stdc++.h>
using namespace std;

#define int long long

int cnt(int x, int base){
    int res = 0;
    while(x % base == 0){
        ++res;
        x /= base;
    }
    return res;
}

struct State{
    int cnt2 = 0, cnt5 = 0;

    int get() const{ return min(cnt2, cnt5); }

    bool operator < (const State& other) const{
        return this->get() < other.get();
    }
};

const int dx[2] = {0, 1}, dy[2] = {1, 0};
const int MAXN = 1000, INF = 1e9;
int n, arr[MAXN + 5][MAXN + 5];
int dp2[MAXN + 5][MAXN + 5], dp5[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][MAXN + 5];

string res;
void solve(){
    for(int i = 2; i <= n; ++i) dp2[i][0] = dp2[0][i] = dp5[i][0] = dp5[0][i] = INF;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(arr[i][j] == 0){
                dp2[i][j] = dp5[i][j] = INF;
                continue;
            }

            dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) + cnt(arr[i][j], 2);
            dp5[i][j] = min(dp5[i - 1][j], dp5[i][j - 1]) + cnt(arr[i][j], 5);
        }
    }
    bool use2 = dp2[n][n] < dp5[n][n];
    int ans = min(dp2[n][n], dp5[n][n]);

    if(!res.empty() && ans >= 1){
        cout << "1\n";
        cout << res << '\n';
        return;
    }
    res = "";

    int cx = n, cy = n;
    while(cx > 1 && cy > 1){
        if(use2){
            if(dp2[cx - 1][cy] < dp2[cx][cy - 1]){
                res += 'D';
                --cx;
            }
            else{
                res += 'R';
                --cy;
            }
        }
        else{
            if(dp5[cx - 1][cy] < dp5[cx][cy - 1]){
                res += 'D';
                --cx;
            }
            else{
                res += 'R';
                --cy;
            }

        }

    }
    if(cx == 1) res += string(cy - 1, 'R');
    if(cy == 1) res += string(cx - 1, 'D');

    cout << ans << '\n';
    reverse(begin(res), end(res));
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> arr[i][j];
            if(res.empty() && arr[i][j] == 0){
                res = string(i - 1, 'D') + string(n - 1, 'R') + string(n - i,'D');
            }
        }
    }

    solve();

    return 0;
}

/*
6
5 5 4 10 5 5
7 10 8 7 6 6
7 1 7 9 7 8
5 5 3 3 10 9
5 8 10 6 3 8
3 10 5 4 3 4
*/
