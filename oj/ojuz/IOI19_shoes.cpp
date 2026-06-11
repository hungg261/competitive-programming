/******************************************************************************
Link: https://oj.uz/problem/view/IOI19_shoes
Code: IOI19_shoes
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-11-08.45.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "shoes.h"
#else
long long count_swaps(vector<int> s);

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
	assert(1 == scanf("%d", &n));
	vector<int> S(2 * n);
	for (int i = 0; i < 2 * n; i++)
		assert(1 == scanf("%d", &S[i]));
	fclose(stdin);

	long long result = count_swaps(S);

	printf("%lld\n", result);
	fclose(stdout);
	return 0;
}
#endif // __________

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        ++idx;
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        ++idx;
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

long long count_swaps(vector<int> s) {
    map<int, vector<int>> mp;
    int n = s.size() / 2;
    for(int i = n * 2 - 1; i >= 0; --i){
        if(s[i] > 0) mp[s[i]].push_back(i);
    }

    vector<pair<int, int>> ranges;
    long long res = 0;
    for(int i = 0; i < n * 2; ++i){
        if(s[i] < 0){
            vector<int>& v = mp[-s[i]];
            int L = i, R = v.back();
            v.pop_back();

            if(L > R){
                swap(L, R);
                ++res;
            }
            ranges.emplace_back(L, R);
        }
    }

    sort(begin(ranges), end(ranges));
    FenwickTree fwt(n * 2 + 1);
    for(int i = 1; i < n * 2; ++i){
        fwt.update(i, 1);
    }

    for(const pair<int, int>& p: ranges){
        int L, R; tie(L, R) = p;

        int pL = fwt.get(L), pR = fwt.get(R);
        res += pR - pL - 1;

        fwt.update(L, 1);
        fwt.update(R + 1, -1);
    }

    return res;
}
