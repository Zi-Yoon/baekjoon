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
        # 분리되지 않은 경우
        print(1)
        # 두점이 같을때 (2 = 3)
        if ((max(A[0], B[0])) == (min(C[0], D[0]))
        and (max(A[1], B[1])) == (min(C[1], D[1]))):
            print(min(C[0], D[0]), min(C[1], D[1]))
		# 두점이 같을때 (4 = 1)
        elif ((max(C[0], D[0])) == (min(A[0], B[0]))
        and (max(C[1], D[1])) == (min(A[1], B[1]))):
            print(min(A[0], B[0]), min(A[1], B[1]))
        # 
        elif(ccw(A, B, D) * ccw(C, D, A) != 0 or ccw(A, B, C) * ccw(C, D, A) != 0):
            print(*B)
        elif(ccw(A, B, D) * ccw(C, D, B) != 0 or ccw(A, B, C) * ccw(C, D, B) != 0):
            print(*A)
    else:
        print(0)

if (ccw(A, B, C) * ccw(A, B, D) <= 0) and (ccw(C, D, A) * ccw(C, D, B) <= 0):
    if (ccw(A, B, C) * ccw(A, B, D) == 0) and (ccw(C, D, A) * ccw(C, D, B) == 0):
        # 한 직선상에 있는 경우 & 다른 직선에서 시작하는 경우 & 한 점에서 시작하는 경우
        oneline_check()
    else:
        # 한 점에서 교차하는 일반적인 경우
        print(1)
        if (x1 != x2 and x3 != x4):
            # 기울기 계산
            m1 = (y2 - y1) / (x2 - x1)
            m2 = (y4 - y3) / (x4 - x3)
            # 상수항 계산
            b1 = y1 - m1 * x1
            b2 = y3 - m2 * x3
            # 공식에 따라 출력
            print((b2 - b1) / (m1 - m2), m1 * ((b2 - b1) / (m1 - m2)) + b1)
        elif (x1 == x2 and x3 != x4):
            # 기울기 계산
            m2 = (y4 - y3) / (x4 - x3)
            # 상수항 계산
            b2 = y3 - m2 * x3
            # 세로직선과 만나기 때문에 x1 대입
            c = m2 * x1 + b2
            # 공식에 따라 출력
            print(x1, c)
        elif (x1 != x2 and x3 == x4):
            # 기울기 계산
            m1 = (y2 - y1) / (x2 - x1)
            # 상수항 계산
            b1 = y1 - m1 * x1
            # 세로직선과 만나기 때문에 x1 대입
            c = m1 * x3 + b1
            # 공식에 따라 출력
            print(x3, c)
else:
    print(0)
