/******************************************************************************
Link: https://oj.uz/problem/view/IZhO17_bootfall
Code: IZhO17_bootfall
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-07-15.34.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500, MAXVAL = 500;
const int MAXSUM = (MAXN + 1) * MAXVAL, MAXHALF = MAXSUM / 2 + 5;
int N, a[MAXN + 5];

namespace Brute{

void solve(){
    vector<int> res;
    int mxsum = 0;
    for(int i = 1; i <= N; ++i)
        mxsum += a[i];

    if(mxsum % 2 == 0) for(int v = 1; v <= 50; ++v){
        a[N + 1] = v;
        int sum = mxsum + v;

        bool ok = true;
        for(int sk = 1; sk <= N + 1; ++sk){
            sum -= a[sk];

            bitset<50> dp;
            dp[0] = true;
            for(int i = 1; i <= N + 1; ++i){
                if(i != sk) dp |= dp << a[i];
            }
            if(!(sum % 2 == 0 && dp[sum / 2])){
                ok = false;
                break;
            }

            sum += a[sk];
        }

        if(ok) res.push_back(v);
    }

    cout << res.size() << "\n";
    for(int v: res) cout << v << " "; cout << endl;
}

}

namespace Solve{

const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
struct State{
    int v1, v2;

    State operator + (const State& other) const {
        State res;
        res.v1 = (1LL * v1 + other.v1) % MOD1;
        res.v2 = (1LL * v2 + other.v2) % MOD2;
        return res;
    }

    State operator - (const State& other) const {
        State res;
        res.v1 = ((1LL * v1 - other.v1) % MOD1 + MOD1) % MOD1;
        res.v2 = ((1LL * v2 - other.v2) % MOD2 + MOD2) % MOD2;
        return res;
    }

    bool exists(){ return v1 || v2; }
};

State mask[MAXSUM + 5];
bool res[MAXSUM + 5], mark[MAXSUM + 5];
void solve(){
    mask[0] = {1, 1};
    int sum = 0;
    for(int i = N; i >= 1; --i){
        for(int j = MAXSUM; j >= a[i]; --j){
            mask[j] = mask[j] + mask[j - a[i]];
        }
        sum += a[i];
    }

    if(sum % 2 == 0 && mask[sum / 2].exists()){
        fill(res + 1, res + MAXSUM + 1, true);
        for(int i = 1; i <= N; ++i){
            for(int j = a[i]; j <= MAXSUM; ++j){
                mask[j] = mask[j] - mask[j - a[i]];
            }
            sum -= a[i];

            fill(mark + 1, mark + MAXSUM + 1, false);
            for(int v = 1; v <= MAXSUM; ++v){
                if(mask[v].exists()){
                    int value = 2 * v - sum;

                    if(1 <= value && value <= MAXSUM)
                        mark[value] = true;
                }
            }

            for(int v = 1; v <= MAXSUM; ++v)
                if(!mark[v]) res[v] = false;

            for(int j = MAXSUM; j >= a[i]; --j){
                mask[j] = mask[j] + mask[j - a[i]];
            }
            sum += a[i];
        }
    }


    cout << count(res + 1, res + MAXSUM + 1, true) << "\n";
    for(int v = 1; v <= MAXSUM; ++v){
        if(res[v]) cout << v << " ";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }

    Solve::solve();

    return 0;
}
