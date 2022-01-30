import sys
sys.setrecursionlimit(int(1e8))
input = sys.stdin.readline

n = int(input())
in_order = list(map(int, input().split(' ')))
post_order = list(map(int, input().split(' ')))
pre_order = []
pos = [0] * n
root = post_order[-1]

for i in range(n):
    pos[in_order[i] - 1] = i
    
def divide(in_start, in_end, post_start, post_end):
    if (in_start > in_end or post_start > post_end):
        return
    root = post_order[post_end] - 1
    pre_order.append(root + 1)
    left = pos[root] - in_start
    divide(in_start, pos[root] - 1, post_start, post_start + left - 1)
    divide(pos[root] + 1, in_end, post_start + left, post_end - 1)

divide(0, n - 1, 0, n - 1)
for i in pre_order:
    print(i, end=' ')