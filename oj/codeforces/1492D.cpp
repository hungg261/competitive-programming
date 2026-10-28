/******************************************************************************
Link: https://codeforces.com/contest/1492/problem/D
Code: 1492D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-19-06.56.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string subtract(string a, string b){
    if(a < b) swap(a, b);

    string result = "";
    int borrow = 0;

    for(int i = a.length() - 1; i >= 0; i--){
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0){
            diff += 2;
            borrow = 1;
        }
        else borrow = 0;
        result += (diff == 1) ? '1' : '0';
    }

    reverse(result.begin(), result.end());
    return result;
}


void solve(){
    int a, b, k;
    cin >> a >> b >> k;

    int len = a + b;

    string x(len, '0'), y(len, '0');
    if(k == 0){
        for(int i = 0; i < b; ++i)
            x[i] = y[i] = '1';
    }
    else{
        if(1 + k >= len){
            cout << "No\n";
            return;
        }

        int cnt1_x = 1, cnt1_y = 1;
        x[1] = '1'; y[1 + k] = '1';

        for(int i = 0; i < len; ++i){
            if(i == 0){
                x[i] = '1';
                y[i] = '1';
                ++cnt1_x;
                ++cnt1_y;
            }
            else{
                if(i == 1 || i == 1 + k) continue;
                else{
                    if(cnt1_x < b) x[i] = '1', ++cnt1_x;
                    if(cnt1_y < b) y[i] = '1', ++cnt1_y;
                }
            }
        }

        if(cnt1_x > b || cnt1_y > b){
            cout << "No\n";
            return;
        }
    }

    string diff = subtract(x, y);
    if(count(begin(diff), end(diff), '1') != k ||
       count(begin(x), end(x), '0') != a ||
       count(begin(y), end(y), '0') != a){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    cout << x << "\n";
    cout << y << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
