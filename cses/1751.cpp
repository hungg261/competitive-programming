/******************************************************************************
Link: https://cses.fi/problemset/task/1751
Code: 1751
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-26-21.00.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n, nxt[MAXN + 5][MAXLG + 5];

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }
}

int lift(int pos, int steps){
    for(int bit = MAXLG; bit >= 0; --bit){
        if(steps >> bit & 1){
            pos = nxt[pos][bit];
        }
    }

    return pos;
}

int mark[MAXN + 5];
int cycle[MAXN + 5], cycID = 0;
int cycleLen[MAXN + 5];

int h[MAXN + 5];

void process(int u){
    if(mark[u] > 0){
        return;
    }
    else if(mark[u] == -1){
        return;
    }
    else if(mark[u] == -2){
        int cur = u;
        int idx = 0;

        mark[cur] = ++idx;
        cycle[cur] = ++cycID;
        ++cycleLen[cycID];

        while(nxt[cur][0] != u){
            cur = nxt[cur][0];

            mark[cur] = ++idx;
            cycle[cur] = cycID;
            ++cycleLen[cycID];
        }
        return;
    }

    mark[u] = -2;
    cycle[u] = -1;

    process(nxt[u][0]);
    if(cycle[u] == -1) h[u] = h[nxt[u][0]] + 1;

    if(mark[u] == -2) mark[u] = -1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1751.INP","r",stdin);
    //freopen("1751.OUT","w",stdout);
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> nxt[i][0];
    }
    compute();

    for(int i = 1; i <= n; ++i) process(i);
    for(int u = 1; u <= n; ++u){
        if(cycle[u] != -1) cout << cycleLen[cycle[u]] << ' ';
        else cout << h[u] + cycleLen[cycle[lift(u, h[u])]] << ' ';
    }

    return 0;
}
