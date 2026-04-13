/******************************************************************************
Link: https://cses.fi/problemset/task/3228
Code: 3228
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-13-17.48.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n;
struct State{
    int l, r;
    vector<int> pos;

    void init(){
        l = 1; r = n;
        for(int i = 1; i <= n; ++i)
            pos.push_back(i);
    }
};

vector<State> states[2];

void solve(){
    vector<int> res(n + 1, -1);

    states[0].emplace_back();
    states[0].back().init();

    for(int h = 0; ; ++h){
        if(states[h & 1].empty()) break;

        vector<int> b(n + 1);
        bool enough = true;
        for(const State& cur: states[h & 1]){
            if(cur.l == cur.r){
                assert(cur.pos.size() == 1);

                res[cur.pos[0]] = cur.l;
                continue;
            }

            int mid = (cur.l + cur.r) >> 1;
            for(int i = cur.l; i <= cur.r; ++i){
                b[i] = i <= mid;
            }

            enough = false;
        }

        if(enough) break;

        cout << "? ";
        for(int i = 1; i <= n; ++i)
            cout << b[i];
        cout << endl;

        string jury;
        cin >> jury;

        jury = "#" + jury;
        while(!states[h & 1].empty()){
            const State cur = states[h & 1].back();
            states[h & 1].pop_back();

            if(cur.l == cur.r) continue;

            vector<int> posL, posR;
            for(int i: cur.pos){
                if(jury[i] == '1')
                    posL.push_back(i);
                else posR.push_back(i);
            }

            int mid = (cur.l + cur.r) >> 1;
            states[h + 1 & 1].push_back({cur.l, mid, posL});
            states[h + 1 & 1].push_back({mid + 1, cur.r, posR});
        }
    }

    cout << "! ";
    for(int i = 1; i <= n; ++i) cout << res[i] << " ";
    cout << endl;
}

signed main(){

    cin >> n;

    solve();


    return 0;
}
