#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
bool mark[MAXN + 5];
int n, a[MAXN + 5];

void solve(){
    stack<int> A, B;
    vector<string> res;
    
    for(int i = n; i >= 1; --i){
        A.push(i);
    }
    
    int i = 1;
    while(i <= n){
        if(mark[a[i]] == true){
            if(B.top() != a[i]){
                cout << "NO\n";
                return;
            }
            
            res.push_back("B->C");
            B.pop();
            
            ++i;
        }
        else{
            if(a[i] == A.top()){
                res.push_back("A->C");
                A.pop();
                
                ++i;
            }
            else{
                res.push_back("A->B");
                
                mark[A.top()] = true;
                B.push(A.top());
                A.pop();
            }
        }
    }
    
    cout << "YES\n";
    for(const string& ans: res){
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    
    solve();
    return 0;
}
