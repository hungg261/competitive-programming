import sys

sys.stdin = open("BAKER.INP", "r")
sys.stdout = open("BAKER.OUT", "w")

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

best = 0
for i in range(1, n):
    if a[i] * b[best] > b[i] * a[best]:
        best = i

print(best + 1)
