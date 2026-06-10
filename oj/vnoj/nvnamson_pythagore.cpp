#include<bits/stdc++.h>
using namespace std;

const int MAX = 5000;
int res[MAX + 5];

int chinh_phuong(int num){
    int sq = sqrt(num);
    
    if(sq * sq == num) return sq;
    else if((sq - 1) * (sq - 1) == num) return sq - 1;
    else if((sq + 1) * (sq + 1) == num) return sq + 1;
    
    return -1;
}

void compute(){
    for(int a = 1; a < MAX / 3; ++a){
        for(int b = a + 1; b * 2 < MAX - a; ++b){
            int tong_ab = a * a + b * b;
            int c = chinh_phuong(tong_ab);
            
            if(c != -1){
                int chu_vi = a + b + c;
                if(chu_vi <= MAX) ++res[chu_vi];
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;

    compute();
    while(t--){
        int n; cin>>n;
        cout << res[n] << '\n';
    }
    return 0;
}
