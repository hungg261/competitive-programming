/******************************************************************************
Link: https://oj.vnoi.info/problem/lqdrace
Code: lqdrace
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-15.20.33
*******************************************************************************/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;

int best_path(int N, int K, int H[][2], int L[]);

#define MAX_N 200005
#define MAX_K 1000005
#define INF 0x3f3f3f3f

static int _N, _K;
static int _H[MAX_N][2];
static int _L[MAX_N];

namespace FastIO {
    const int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    int p = BUF_SIZE;

    inline char nc() {
        if (p == BUF_SIZE) {
            p = 0;
            int r = fread(buf, 1, BUF_SIZE, stdin);
            if (!r) return EOF;
        }
        return buf[p++];
    }

    inline void read(int &x) {
        x = 0;
        char c = nc();
        while (c < '0' || c > '9') c = nc();
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = nc();
        }
    }
}

void read_input()
{
    FastIO::read(_N);
    FastIO::read(_K);
    for(int i = 0; i < _N - 1; ++i){
        FastIO::read(_H[i][0]);
        FastIO::read(_H[i][1]);
        FastIO::read(_L[i]);
//        --_H[i][0]; --_H[i][1];
    }
}

int main()
{
    read_input();
    printf("%d\n", best_path(_N, _K, _H, _L));
    return 0;
}

int n, k, global_res = INF;
int head[MAX_N], to_v[MAX_N << 1], weight[MAX_N << 1], nxt[MAX_N << 1], edge_cnt;
int sz[MAX_N];
bool removed[MAX_N];
int freq[MAX_K];

int d_sum[MAX_N], d_len[MAX_N], d_cnt;
int touched[MAX_N], t_cnt;

inline void add_edge(int u, int v, int w){
    to_v[edge_cnt] = v; weight[edge_cnt] = w; nxt[edge_cnt] = head[u]; head[u] = edge_cnt++;
    to_v[edge_cnt] = u; weight[edge_cnt] = w; nxt[edge_cnt] = head[v]; head[v] = edge_cnt++;
}

void compute(int u, int prv){
    sz[u] = 1;
    for(int e = head[u]; ~e; e = nxt[e]){
        int v = to_v[e];
        if(v == prv || removed[v]) continue;
        compute(v, u);
        sz[u] += sz[v];
    }
}

int find_centroid(int u, int prv, int half){
    for(int e = head[u]; ~e; e = nxt[e]){
        int v = to_v[e];
        if(v != prv && !removed[v] && sz[v] > half)
            return find_centroid(v, u, half);
    }
    return u;
}

void getDepth(int u, int prv, int len, int sum){
    if(sum > k || len >= global_res) return;
    d_sum[d_cnt] = sum;
    d_len[d_cnt++] = len;

    for(int e = head[u]; ~e; e = nxt[e]){
        int v = to_v[e];
        if(v == prv || removed[v]) continue;
        getDepth(v, u, len + 1, sum + weight[e]);
    }
}

void decompose(int u){
    compute(u, -1);
    int centroid = find_centroid(u, -1, sz[u] >> 1);

    removed[centroid] = true;
    t_cnt = 0;

    for(int e = head[centroid]; ~e; e = nxt[e]){
        int v = to_v[e];
        if(removed[v]) continue;

        d_cnt = 0;
        getDepth(v, centroid, 1, weight[e]);

        for(int i = 0; i < d_cnt; ++i){
            int d = d_sum[i], len = d_len[i];
            if(len + freq[k - d] < global_res){
                global_res = len + freq[k - d];
            }
        }
        for(int i = 0; i < d_cnt; ++i){
            int d = d_sum[i], len = d_len[i];
            if(len < freq[d]){
                if(freq[d] == INF) touched[t_cnt++] = d;
                freq[d] = len;
            }
        }
    }

    for(int i = 0; i < t_cnt; ++i) freq[touched[i]] = INF;

    for(int e = head[centroid]; ~e; e = nxt[e]){
        int v = to_v[e];
        if(!removed[v] && sz[v] > 1) decompose(v);
    }
}

int best_path(int N, int K, int H[][2], int L[]){
    n = N; k = K;
    memset(head, -1, n * sizeof(int));
    memset(freq, 0x3f, (k + 1) * sizeof(int));
    freq[0] = 0;

    for(int i = 0; i < n - 1; ++i){
        add_edge(H[i][0], H[i][1], L[i]);
    }

    decompose(0);
    return (global_res >= INF ? -1 : global_res);
}
