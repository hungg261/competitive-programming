/******************************************************************************
Link: https://cses.fi/problemset/task/1076
Code: 1076
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-12-10.38.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// unfinished, goto v2 instead.

const int MAXN = 2e5;
int arr[MAXN + 5], n, k;

void print(const multiset<int>& ms){
    for(int ele: ms) cerr << ele << " ";
    cerr << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    multiset<int> ms[2];
    for(int i = 1; i <= n; ++i){
        if(ms[0].size() == ms[1].size()){
            ms[1].insert(arr[i]);
        }
        else{
            ms[0].insert(arr[i]);
        }

        if(i > k){
            int s = ms[0].size() >= ms[1].size() ? 0 : 1;

            auto it = ms[s].find(arr[i - k]);
            if(it != ms[s].end()){
                ms[s].erase(it);
            }
            else{
                ms[s ^ 1].erase(ms[s ^ 1].find(arr[i - k]));

                ms[s ^ 1].insert(*ms[s].begin());
                ms[s].erase(ms[s].begin());
            }
        }

        cerr << "L: "; print(ms[0]);
        cerr << "R: "; print(ms[1]);
        cerr << "\n";
    }

    cout << "\n";

    return 0;
}
