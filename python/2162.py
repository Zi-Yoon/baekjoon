import sys
from collections import defaultdict
sys.setrecursionlimit(int(1e5))
input = sys.stdin.readline

# ccw 알고리즘 -> 외적을 이용한 sin 계산을 통해 각각의 점이
# 해당 선분을 통과하는지 안하는지를 체크 해준다.
# sin은 180이 넘어가면 음수가 되기 때문
def ccw(A, B, C): 
    x1, y1 = A
    x2, y2 = B
    x3, y3 = C
    temp = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) 
    if temp > 0: 
        return 1 
    elif temp < 0: 
        return -1 
    else: 
        return 0

# 완전 분리된 선분 인지를 체크
def oneline_check(A, B, C, D):
    if ((max(A[0], B[0])) >= (min(C[0], D[0]))
        and (min(A[0], B[0])) <= (max(C[0], D[0]))
        and (max(A[1], B[1])) >= (min(C[1], D[1]))
            and (min(A[1], B[1])) <= (max(C[1], D[1]))):
        return True
    else:
        return False

def check_cross(A, B, C, D):
    if (ccw(A, B, C) * ccw(A, B, D) <= 0) and (ccw(C, D, A) * ccw(C, D, B) <= 0):
        if (ccw(A, B, C) * ccw(A, B, D) == 0) and (ccw(C, D, A) * ccw(C, D, B) == 0):
            return oneline_check(A, B, C, D)
        else:
            return True
    else:
        return False

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

n = int(input())
parent = [-1 for i in range(n + 1)]
lines = [[]] + [list(map(int, input().split())) for i in range(n)]

# 입력받아서 저장
for i in range(1, n):
    for j in range(i + 1, n + 1):
        x1, y1, x2, y2 = lines[i]
        x3, y3, x4, y4 = lines[j]
        A, B, C, D = [x1, y1], [x2, y2], [x3, y3], [x4, y4]
        if check_cross(A, B, C, D):
            union(i, j)

cnt = 0
max_val = 0
for i in parent[1:]:
    if i < 0:
        cnt += 1
        max_val = max(max_val, abs(i))
print(cnt)
print(max_val)