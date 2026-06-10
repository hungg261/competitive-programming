#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int N, K;
int T[MAXN + 5];

namespace Subtask1{

void Try(int idx, vector<int>& C, int& res){
    if((int)C.size() == K){
        int cur = 0;
        for(int i = 0; i + 1 < K; ++i){
            cur += T[C[i + 1] - 1] - T[C[i]] + 1;
        }
        cur += T[N] - T[C.back()] + 1;

        res = min(res, cur);
        return;
    }
    if(idx > N) return;

    C.push_back(idx);
    Try(idx + 1, C, res);
    C.pop_back();

    Try(idx + 1, C, res);
}

void solve(){
    int res = INT_MAX;
    vector<int> C = {1};
    Try(2, C, res);

    cout << res << "\n";
}

}

namespace SubtaskFull{

void solve(){
    vector<int> diff;
    for(int i = 1; i + 1 <= N; ++i){
        diff.push_back(T[i + 1] - T[i]);
    }
    sort(begin(diff), end(diff));

    int res = T[N] - T[1] + 1;
    for(int i = 2; i <= K; ++i){
        res -= diff.back() - 1;
        diff.pop_back();
    }

    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; ++i){
        cin >> T[i];
    }

    if(N <= K){
        cout << N << "\n";
        return 0;
    }

    SubtaskFull::solve();

    return 0;
}
