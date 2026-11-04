/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_qg_diepkhuc
Code: nvnamson_qg_diepkhuc
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-03-22.05.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int N, K;
string S;

namespace Subtask1{

void solve(){
    for(int d = N / 2; d >= 1; --d){
        for(int i = 0; i + 2 * d <= N; ++i){
            int mm = 0;
            for(int j = 0; j < d; ++j){
                if(S[i + j] != S[i + d + j]) ++mm;
            }

            if(mm <= K){
                cout << 2 * d << " " << i + 1 << "\n";
                return;
            }
        }
    }

    cout << "0 0\n";
}

}

namespace Subtask2{

void solve(){
    for(int d = N / 2; d >= 1; --d){
        int mm = 0;
        for(int j = 0; j < d; ++j){
            if(S[j] != S[j + d]) ++mm;
        }

        if(mm <= K){
            cout << 2 * d << " 1\n";
            return;
        }

        for(int i = 1; i + 2 * d <= N; ++i){
            if(S[i - 1] != S[i - 1 + d]) --mm;
            if(S[i - 1 + d] != S[i - 1 + 2 * d]) ++mm;
            if(mm <= K){
                cout << 2 * d << " " << i + 1 << "\n";
                return;
            }
        }
    }
    cout << "0 0\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    cin >> S;

    if(N <= 300) Subtask1::solve();
    else Subtask2::solve();

    return 0;
}
