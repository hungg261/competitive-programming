/******************************************************************************
Link: https://oj.uz/problem/view/NOI18_knapsack
Code: NOI18_knapsack
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-06-08.16.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Item{
    int V, W;
};

int Knapsack(const vector<Item>& I, int S){
    int n = I.size();
    vector<int> dp(S + 1, 0);

    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        const Item& item = I[i - 1];
        for(int j = S; j >= item.W; --j){
            dp[j] = max(dp[j], dp[j - item.W] + item.V);
        }
    }

    return *max_element(begin(dp), end(dp));
}

void add(vector<Item>& I, int V, int W, int K){
    for(int b = 0; b < 31; ++b){
        int mask = 1 << b;
        if(K >= mask){
            I.push_back({V * mask, W * mask});
            K -= mask;
        }
    }

    if(K) I.push_back({V * K, W * K});
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int S, N;
    cin >> S >> N;

    vector<vector<pair<int, int>>> Groups(S + 1);
    for(int i = 1; i <= N; ++i){
        int V, W, K;
        cin >> V >> W >> K;
        K = min(K, S / W);

        Groups[W].push_back({V, K});
    }

    vector<Item> I;
    for(int W = 1; W <= S; ++W){
        int sz = Groups[W].size();
        if(!sz) continue;

        sort(begin(Groups[W]), end(Groups[W]), greater<pair<int, int>>());

        int limit = S / W, collected = 0;
        for(int i = 0; i < sz && collected < limit; ++i){
            int take = min(Groups[W][i].second, limit - collected);
            collected += take;

            while(take--) I.push_back({Groups[W][i].first, W});
        }
    }

    cout << Knapsack(I, S) << "\n";

    return 0;
}
