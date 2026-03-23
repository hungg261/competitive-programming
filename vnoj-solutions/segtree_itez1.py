import sys

# 1. Faster Input: Replace input() with sys.stdin.readline
# This is crucial for problems with a large number of inputs/queries.
input = sys.stdin.readline 

# Increase recursion limit. While 10^6 is set, a slightly tighter bound is fine for logN.
# For N=250,000, log2(N) is about 18, so stack depth won't exceed ~2*18 (for get/update).
sys.setrecursionlimit(10**4)

n = int(input())

# Initialize nodes for a segment tree.
# 4*N is a common safe upper bound for segment tree array size.
# We initialize with a very small number since we're looking for maximums.
nodes = [-10**9] * (4 * n + 5) 

# Original array (0-indexed for convenience when reading, but segment tree uses 1-indexed ranges)
arr = list(map(int, input().split()))

# 2. Optimized Tree Construction:
# Instead of N separate update calls (which is O(N log N)),
# a bottom-up build function constructs the tree in O(N) time.
def build(id, l, r):
    if l == r:
        nodes[id] = arr[l - 1] # arr is 0-indexed, segment tree ranges are 1-indexed
        return
    mid = (l + r) // 2
    build(id * 2, l, mid)
    build(id * 2 + 1, mid + 1, r)
    nodes[id] = max(nodes[id * 2], nodes[id * 2 + 1])

# Call build to construct the tree initially
build(1, 1, n)

# Point update function (value at idx becomes val)
def update(id, l, r, idx, val):
    # If the current segment [l, r] does not contain idx, do nothing
    if r < idx or idx < l:
        return
    # If we reached a leaf node, update its value
    if l == r:
        nodes[id] = val
        return
    
    # Otherwise, recurse into children
    mid = (l + r) // 2
    update(id * 2, l, mid, idx, val)
    update(id * 2 + 1, mid + 1, r, idx, val)
    # Update the current node based on its children's new values
    nodes[id] = max(nodes[id * 2], nodes[id * 2 + 1])

# Range query function (get max in range [u, v])
def get(id, l, r, u, v):
    # If the current segment [l, r] is completely outside the query range [u, v],
    # return the identity element for max (a very small number)
    if v < l or r < u: 
        return -10**9 
    # If the current segment [l, r] is completely inside the query range [u, v],
    # return its stored value
    if u <= l and r <= v: 
        return nodes[id]
    
    # Otherwise, recurse into children and combine their results
    mid = (l + r) // 2
    return max(get(id * 2, l, mid, u, v),
               get(id * 2 + 1, mid + 1, r, u, v))

q = int(input())
results = [] # 3. Collect results and print all at once for faster output

for _ in range(q):
    type, x, y = map(int, input().split())
    if type == 1:
        update(1, 1, n, x, y)
    else:
        results.append(str(get(1, 1, n, x, y))) # Store result as string

# Print all collected results, joined by newlines.
# This avoids repeated calls to sys.stdout.write, which can be slow.
sys.stdout.write("\n".join(results) + "\n")
