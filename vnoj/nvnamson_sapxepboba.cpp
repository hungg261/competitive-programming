#include<bits/stdc++.h>
#define int long long
using namespace std;

int C(int n,int k){
    // nu n<0 th chc chn khng c cch no chn ra k phn t c
    if(n<0)return 0;
    
    if(k==0) return 1; // nC0
    if(k==1) return n; // nC1
    if(k==2) return n*(n-1)/2; // nC2
    if(k==3) return n*(n-1)*(n-2)/6; // nC3
    
    return -1;
}

int dem_tong_bang_s(int d,int S,int N) {
	int ans=0;

	for(int i=0; i<=d; ++i) {
		int cur=C(d,i) * C(S-N*i-1, d-1);
		
		if(i%2==0) ans+=cur;
		else ans-=cur;
	}

	return ans;
}

pair<int,int> find_sum(int N,int T,int d) {
	int tong_cong_don=0;
	for(int sum=3; sum<=N*3; ++sum) {
	    // gi tr trc khi cng dn
		int temp=tong_cong_don;
		
		// thc hin cng dn
		tong_cong_don+=dem_tong_bang_s(d,sum,N);
		
		if(T<=tong_cong_don) {
		    //  tm c tng tha mn, tr li tng "S" v v tr "pos"
			return {sum,T-temp};
		}
	}
	return {-1,-1};
}

void tim_x2(int sum,int pos,int N) {
	for(int x2=1; x2<=N; ++x2) {
		int x3=sum-x2;

        // nu x3 tha iu kin th ta va tm c mt cp tha mn
		if(1<=x3&&x3<=N) {
		    // lc ny cn li pos-1 cp cn xt na nn ta tr pos cho 1
			--pos;
			
			// nu khng cn cp cn xt, ngha l cp (x2,x3) hin ti l cp cn tm
			if(pos==0) {
			    // in ra kt qu v dng li
				cout<<x2<<' '<<x3<<'\n';
				return;
			}
		}
	}
}

void tim_x1(int sum,int pos,int N) {
	int tong_cong_don=0;
	for(int x1=1; x1<=N; ++x1) {
	    // gi tr trc khi cng dn
		int temp=tong_cong_don;
		
		// thc hin cng dn
		tong_cong_don+=dem_tong_bang_s(2,sum-x1,N);
		
		if(pos<=tong_cong_don) {
		    //  tm c x1 tha mn
			cout<<x1<<' ';
			
			// bt u thc hin tm x2
			tim_x2(sum-x1,pos-temp,N);
			return;
		}
	}
}

void solve(int N,int T) {
	// tng ca b ba cn tm v v tr ca b ba  trong cc b ba c tng tng t 
	int sum,pos;
	tie(sum,pos)=find_sum(N,T,3);
    
    // bt u tm x1
	tim_x1(sum,pos,N);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N,T;
	cin>>N>>T;

	solve(N,T);
	return 0;
}
