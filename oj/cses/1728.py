from decimal import Decimal, getcontext, ROUND_HALF_EVEN

getcontext().prec = 50
getcontext().rounding = ROUND_HALF_EVEN

n = int(input())
arr = [0] + list(map(int, input().split()))

ans = Decimal(0)

for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        total = 0
        ai = arr[i]
        aj = arr[j]

        for k in range(1, ai + 1):
            total += min(k - 1, aj)

        ans += Decimal(total) / (Decimal(ai) * Decimal(aj))

print(ans.quantize(Decimal("0.000000")))

