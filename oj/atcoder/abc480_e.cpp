/******************************************************************************
Link: https://atcoder.jp/contests/abc480/tasks/abc480_e
Code: abc480_e
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-17-19.23.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int N;

void brute(){
    auto get = [](int r, int d, int len){
        int res = 1;
        for(int i = 0; i < len; ++i){
            if(r <= 0) return LLONG_MAX;
            res *= r;
            r -= d;
        }
        return res;
    };

    for(int i = 1; i <= min(20LL, N); ++i){
        for(int len = 3; len <= i; ++len){
            for(int d = 1; d <= i; ++d){
                if(get(i, d, len) <= N){
                    cerr << i << " " << d << " " << len << " " << get(i, d, len) << " ok\n";
                }
            }
        }
    }

}


void solve(){
    auto get = [&N](int r, int d, int len){
        int res = 1;
        for(int i = 0; i < len; ++i){
            if(r <= 0) return N + 1;
            else if(res > N / r) return N + 1;
            res *= r;
            r -= d;
        }
        return res;
    };

    cerr << "try: " << get(15, 7, 3) << endl;;

    int res = 0;
    for(int len = 3; len <= 20; ++len){
        for(int i = len; i * i * i <= N; ++i){
            int bound = (i - 1) / (len - 1);
            if(get(i, bound, len) > N) continue;

            int lo = 1, hi = bound, d = 0;
//            cerr << i << "! " << lo << " " << hi << endl;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(get(i, mid, len) <= N){
                    d = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }

//            cerr << i << " " << len << ": " << bound - d + 1 << endl;
            res += bound - d + 1;
        }
    }

    cout << res << "\n";

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

//    brute();
    solve();

    return 0;
}
