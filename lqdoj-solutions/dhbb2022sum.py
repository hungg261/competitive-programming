n,a,b=map(int,input().split())
mod=10**9+7

dsqrt=lambda q:q*(q-1)*(4*q+1)//6+q*(n-q*q+1)
print((a*n*(n+1)//2+b*dsqrt(int(n**.5)))%mod)