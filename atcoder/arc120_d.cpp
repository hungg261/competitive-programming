/******************************************************************************
Link: https://atcoder.jp/contests/arc120/tasks/arc120_d
Code: arc120_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-08.28.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int a[MAXN * 2 + 5], values[MAXN * 2 + 5], n;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n * 2; ++i){
        cin >> a[i];
        values[i] = a[i];
    }
    sort(values, values + n * 2);

    multiset<int> s, l;
    for(int i = 0; i < n; ++i) s.insert(values[i]);
    for(int i = n; i < n * 2; ++i) l.insert(values[i]);

    vector<int> L, R;
    string res(n * 2, '?');
    for(int i = 0; i < n * 2; ++i){
        if(s.find(a[i]) != s.end()){
            if(!R.empty()){
                res[R.back()] = '(';
                res[i] = ')';
                R.pop_back();
            }
            else L.push_back(i);

            s.erase(s.find(a[i]));
        }
        else{
            if(!L.empty()){
                res[L.back()] = '(';
                res[i] = ')';
                L.pop_back();
            }
            else R.push_back(i);

            l.erase(l.find(a[i]));
        }
    }

    cout << res << endl;
    assert(res.find('?') == string::npos);

    return 0;
}
