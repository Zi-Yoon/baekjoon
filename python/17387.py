import sys
from collections import defaultdict
sys.setrecursionlimit(int(1e5))
input = sys.stdin.readline

# ccw 알고리즘 -> 외적을 이용한 sin 계산을 통해 각각의 점이 
# 해당 선분을 통과하는지 안하는지를 체크 해준다. 
# sin은 180이 넘어가면 음수가 되기 때문
def ccw(a, b, c):
    return (a[0]*b[1]+b[0]*c[1]+c[0]*a[1] - (b[0]*a[1]+c[0]*b[1]+a[0]*c[1]))

x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
A, B, C, D = [x1, y1], [x2, y2], [x3, y3], [x4, y4]

# 완전 분리된 선분 인지를 체크
def oneline_check():
    if ((max(A[0], B[0])) >= (min(C[0], D[0]))
    and (min(A[0], B[0])) <= (max(C[0], D[0]))
    and (max(A[1], B[1])) >= (min(C[1], D[1]))
    and (min(A[1], B[1])) <= (max(C[1], D[1]))):
        print(1)
    else:
        print(0)

if (ccw(A, B, C) * ccw(A, B, D) <= 0) and (ccw(C, D, A) * ccw(C, D, B) <= 0):
    if (ccw(A, B, C) * ccw(A, B, D) == 0) and (ccw(C, D, A) * ccw(C, D, B) == 0):
        oneline_check()
    else:
        print(1)
else:
    print(0)
