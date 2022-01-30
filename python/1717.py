import sys
from collections import defaultdict
sys.setrecursionlimit(int(1e5))
input = sys.stdin.readline

def find(x):
    if parent[x] < 0:
        return x
    p = find(parent[x])
    parent[x] = p
    return p

def union(x, y):
    x = find(x)
    y = find(y)

    if x == y:
        return

    if parent[x] < parent[y]:
        parent[x] += parent[y]
        parent[y] = x
    else:
        parent[y] += parent[x]
        parent[x] = y

n, m = map(int, input().split())
parent = [-1 for i in range(n + 1)]
for _ in range(m):
    check, a, b = map(int, input().split())
    if not check:
        union(a, b)
    if check:
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")
