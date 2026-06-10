/******************************************************************************
Link: https://oj.uz/problem/view/IOI21_dna
Code: IOI21_dna
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-10.59.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "dna.h"
#else

void init(string a, string b);
int get_distance(int x, int y);

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
	assert(scanf("%d %d", &n, &q) == 2);
	char A[n+1], B[n+1];
	assert(scanf("%s", A) == 1);
	assert(scanf("%s", B) == 1);
	std::string a = std::string(A);
	std::string b = std::string(B);
	std::vector<int> x(q), y(q);
	for (int i = 0; i < q; i++) {
		assert(scanf("%d %d", &x[i], &y[i]) == 2);
	}
	fclose(stdin);
	std::vector<int> results(q);
	init(a, b);
	for (int i = 0; i < q; i++) {
		results[i] = get_distance(x[i], y[i]);
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", results[i]);
	}
	fclose(stdout);
	return 0;
}

#endif // __________

int f(char c){
    if(c == 'A') return 0;
    else if(c == 'T') return 1;
    else if(c == 'C') return 2;
    exit(-1);
}

vector<array<array<int, 3>, 3>> pre;
vector<array<int, 3>> freqA, freqB;
string A, B;
int n;

void init(string a, string b){
    A = "#" + a; B = "#" + b;
    n = a.size();

    pre.resize(n + 1);
    for(int c1 = 0; c1 < 3; ++c1)
        for(int c2 = 0; c2 < 3; ++c2)
            pre[0][c1][c2] = 0;

    freqA.resize(n + 1); freqB.resize(n + 1);
    freqA[0] = {0, 0, 0}; freqB[0] = {0, 0, 0};

    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1];
        ++pre[i][f(A[i])][f(B[i])];

        freqA[i] = freqA[i - 1];
        ++freqA[i][f(A[i])];

        freqB[i] = freqB[i - 1];
        ++freqB[i][f(B[i])];
    }
}

int get_distance(int l, int r){
    ++l; ++r;

    for(int c = 0; c < 3; ++c){
        int cntA = freqA[r][c] - freqA[l - 1][c];
        int cntB = freqB[r][c] - freqB[l - 1][c];

        if(cntA != cntB) return -1;
    }

    array<array<int, 3>, 3> cnt;
    for(int c1 = 0; c1 < 3; ++c1)
        for(int c2 = 0; c2 < 3; ++c2)
            cnt[c1][c2] = pre[r][c1][c2] - pre[l - 1][c1][c2];

    int res = 0, rem = 0;
    for(int c1 = 0; c1 < 3; ++c1){
        for(int c2 = c1 + 1; c2 < 3; ++c2){
            res += min(cnt[c1][c2], cnt[c2][c1]);
            rem += abs(cnt[c1][c2] - cnt[c2][c1]);
        }
    }

    res += 2 * (rem / 3);
    return res;
}
