#include<bits/stdc++.h>
using namespace std;

string x,y;

void xuli_min(){
    int n=x.size(),m=y.size(),
        i=0,j=0;
    while(i<n&&j<m){
        if(x[i]<y[j]){
            cout<<x[i];
            ++i;
        }
        else if(x[i]>y[j]){
            cout<<y[j];
            ++j;
        }
        else{
            string lastx=x.substr(i),lasty=y.substr(j);
            if(lastx+lasty<lasty+lastx){
                cout<<x[i];
                ++i;
            }
            else{
                cout<<y[j];
                ++j;
            }
        }
    }
    while(i<n){
        cout<<x[i];
        ++i;
    }
    while(j<m){
        cout<<y[j];
        ++j;
    }
    cout<<'\n';
}

void xuli_max(){
    int n=x.size(),m=y.size(),
        i=0,j=0;
    while(i<n&&j<m){
        if(x[i]>y[j]){
            cout<<x[i];
            ++i;
        }
        else if(x[i]<y[j]){
            cout<<y[j];
            ++j;
        }
        else{
            string lastx=x.substr(i),lasty=y.substr(j);
            if(lastx+lasty>lasty+lastx){
                cout<<x[i];
                ++i;
            }
            else{
                cout<<y[j];
                ++j;
            }
        }
    }
    while(i<n){
        cout<<x[i];
        ++i;
    }
    while(j<m){
        cout<<y[j];
        ++j;
    }
    cout<<'\n';
}

void solve(){
    xuli_min();
    xuli_max();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>x>>y;
    
    solve();
    return 0;
}
