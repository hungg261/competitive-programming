n,k=map(int,input().split())

def colsum(col,n):
    n-=col-1
    return (n**3+(3*col-3)*n**2+(3*col**2)*n)//2

total=n*(n+1)//2
ans=(2+total*3-1)*total//2
for i in range(1,k+1):
    ans-=colsum(i,n)

print(ans)