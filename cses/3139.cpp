/******************************************************************************
Link: https://cses.fi/problemset/task/3139
Code: 3139
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-11-11.56.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool ask(int a, int b){
    cout << "? " << a << " " << b << endl;

    string status;
    cin >> status;

    return status == "YES";
}

vector<int> Solve(int l, int r){
    if(l == r) return {l};

    int mid = (l + r) >> 1;
    vector<int> Left = Solve(l, mid);
    vector<int> Right = Solve(mid + 1, r);

    vector<int> res;

    int i = 0, j = 0;
    int szL = mid - l + 1, szR = r - mid;
    while(i < szL && j < szR){
        if(ask(Left[i], Right[j]))
            res.push_back(Left[i++]);
        else res.push_back(Right[j++]);
    }

    while(i < szL) res.push_back(Left[i++]);
    while(j < szR) res.push_back(Right[j++]);

    return res;
}

signed main(){

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    int e = 0;

    for(int i: Solve(1, n)) arr[i] = ++e;

    cout << "! ";
    for(int i = 1; i <= n; ++i)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
