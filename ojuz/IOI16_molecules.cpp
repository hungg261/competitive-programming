/******************************************************************************
Link: https://oj.uz/problem/view/IOI16_molecules
Code: IOI16_molecules
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-06-11.32.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "molecules.h"
#else

std::vector<int> find_subset(int l, int r, std::vector<int> w);
bool brute(int l, int r, std::vector<int> w);

#define STRESS
int main() {

    #ifndef STRESS
    int n, l, u;
    assert(3 == scanf("%d %d %d", &n, &l, &u));
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        assert(1 == scanf("%d", &w[i]));
    std::vector<int> result = find_subset(l, u, w);


    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); i++)
        printf("%d%c", result[i], " \n"[i == (int)result.size() - 1]);

    #else
    srand(time(0));
    while(true){
        int n = rand() % 1000 + 1;
        vector<int> w(n);
        for(int i = 0; i < n; ++i) w[i] = rand() % 2 + 1;
        int rg = *max_element(begin(w), end(w)) - *min_element(begin(w), end(w));
        int l = rand() % 10000 + 1, u = l + rg + rand() % 10000;

        if(!find_subset(l, u, w).empty() != brute(l, u, w)){
            cerr << n << " " << l << " " << u << "\n";
            for(int x: w) cerr << x << " "; cerr << endl;
            break;
        }
//        else cerr << "CORRECT\n";
    }

    #endif
}

#endif // __________

bool brute(int l, int r, std::vector<int> w) {
    constexpr int MAXVAL = 500000;
    bitset<MAXVAL> dp;

    dp[0] = true;
    for(int x: w){
        dp |= dp << x;
    }

    for(int i = l; i <= r; ++i)
        if(dp[i]) return true;
    return false;
}

std::vector<int> find_subset(int l, int r, std::vector<int> w) {
    int n = w.size();
    vector<pair<int, int>> W;
    for(int i = 0; i < n; ++i) W.push_back({w[i], i});

    sort(begin(W), end(W));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    long long sum = 0;
    for(int i = 0; i < n; ++i){
        sum += W[i].first;
        pq.push({W[i].first, W[i].second});

        while(!pq.empty() && sum > r){
            sum -= pq.top().first;
            pq.pop();
        }

        if(l <= sum && sum <= r) break;
    }

    vector<int> res;
    if(l <= sum && sum <= r) while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}
