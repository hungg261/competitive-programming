#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    if(n != 1 && n <= 3){
        cout << "NO SOLUTION\n";
        return 0;
    }

    for(int i = n - 1; i >= 1; i -= 2){
        cout << i << ' ';
    }
    for(int i = n; i >= 1; i -= 2){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
