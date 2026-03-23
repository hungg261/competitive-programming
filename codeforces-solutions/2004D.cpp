#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<string> states;
void generateStates(){
    for(char a: "BGRY"){
        for(char b: "BGRY"){
            if(a < b) states.push_back(string(1, a) + string(1, b));
        }
    }
}

bool linked(const string &A, const string &B){
    for(char a: A){
        for(char b: B){
            if(a == b) return true;
        }
    }
    return false;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        string state;
        cin >> state;

        sort(begin(state), end(state));
        arr[i] = find(begin(states), end(states), state) - begin(states);
    }

    const int STATESIZE = states.size();
    vector<vector<int>> L(n + 1, vector<int>(STATESIZE, -INF)), R(n + 1, vector<int>(STATESIZE, INF));
    int last[STATESIZE] = {};
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < STATESIZE; ++j){
            if(arr[i] != j && linked(states[arr[i]], states[j])){
                int &l = last[j];
                if(l != 0) L[i][arr[i]] = max(L[i][arr[i]], l);
            }
        }
        last[arr[i]] = i;
    }

    memset(last, 0, sizeof last);
    for(int i = n; i >= 1; --i){
        for(int j = 0; j < STATESIZE; ++j){
            if(arr[i] != j && linked(states[arr[i]], states[j])){
                int &l = last[j];
                if(l != 0) R[i][arr[i]] = min(R[i][arr[i]], l);
            }
        }
        last[arr[i]] = i;
    }

//    for(int i = 1; i <= n; ++i) cerr << R[i][arr[i]] << ' '; cerr << '\n';

    while(q--){
        int a, b;
        cin >> a >> b;

        if(a > b) swap(a, b);
//            cerr << states[arr[a]] << ' ' << states[arr[b]] << ' ' << linked(states[arr[a]], states[arr[b]]) << '\n';
        if(linked(states[arr[a]], states[arr[b]])){
            cout << b - a << '\n';
            continue;
        }

        int ans1 = L[a][arr[a]] != -INF ? abs(a - L[a][arr[a]]) + abs(L[a][arr[a]] - b) : INF,
            ans2 = R[a][arr[a]] != INF ? abs(a - R[a][arr[a]]) + abs(R[a][arr[a]] - b) : INF;

//        cerr << "d: " << a << ' ' << b << ' ' << L[a][arr[a]] << ' ' << R[a][arr[a]] << ' ' << ans1 << ' ' << ans2 << '\n';
        int ans = min(ans1, ans2);

        cout << (ans == INF ? -1 : ans) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    generateStates();
    while(t--){
        solve();
    }

    return 0;
}

/*
1
4 5
BR BR GY GR
1 2
3 1
4 4
1 4
4 2
*/
