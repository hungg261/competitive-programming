/******************************************************************************
Link: https://atcoder.jp/contests/arc067/tasks/arc067_d?lang=en
Code: arc067_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-22-15.44.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e3, MAXM = 200;
int A[MAXN + 5], B[MAXN + 5][MAXM + 5];
int n, m;

int L[MAXN + 5][MAXM + 5], R[MAXN + 5][MAXM + 5];

void trau();
void compute(){
    for(int j = 1; j <= m; ++j){
        vector<int> sta;
        for(int i = 1; i <= n; ++i){
            while(!sta.empty() && B[sta.back()][j] <= B[i][j]) sta.pop_back();
            L[i][j] = sta.empty() ? 0 : sta.back();

            sta.push_back(i);
        }

        sta.clear();
        for(int i = n; i >= 1; --i){
            while(!sta.empty() && B[sta.back()][j] <= B[i][j]) sta.pop_back();
            R[i][j] = sta.empty() ? n + 1 : sta.back();

            sta.push_back(i);
        }

        for(int i = 1; i <= n; ++i){
            cerr << i << ' ' << j << ": " << L[i][j] + 1 << ' ' << R[i][j] - 1 << '\n';
        }
    }
}

vector<int> wait[MAXN + 5];
void solve(){
    for(int l = 1; l <= n; ++l){
        for(int j = 1; j <= m; ++j) wait[l].push_back(B[l][j]);
        int cur = 0;
        for(int r = l; r <= n; ++r){
            for(int v: wait[r]){

            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i < n; ++i){
        cin >> A[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> B[i][j];
        }
    }

//    trau();
    compute();

    return 0;
}

void trau(){
    int res = 0;
    for(int l = 1; l <= n; ++l){
        int subtracted = 0;
        for(int r = l; r <= n; ++r){
            int cur = 0;
            for(int j = 1; j <= m; ++j){
                int best = 0;
                for(int i = l; i <= r; ++i){
                    best = max(best, B[i][j]);
                }
                cur += best;
            }

            res = max(res, cur - subtracted);
            subtracted += A[r];
        }
    }

    cout << res << '\n';
}
