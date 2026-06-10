l,h=map(int,input().split())

def solve(n):
    if n==0:return 0
    x=int((1+(8*n-7)**.5)//2)
    return x*(x-1)*(2*x-1)//6+x*(n-x*(x-1)//2)

MOD=10**9+7
print((solve(h)-solve(l-1))%MOD)