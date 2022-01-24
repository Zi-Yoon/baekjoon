import sys

sys.setrecursionlimit(10 ** 8)
def input(): return sys.stdin.readline().rstrip()

str = input()
n = len(str)

# 최대값 초기화
dp = [2500 for _ in range(n + 1)]
dp[-1] = 0

# 0으로 초기화 is_palendrom check palendrom -> 1
is_p = [[0 for j in range(n)] for i in range(n)]

for i in range(n):
    is_p[i][i] = 1

for i in range(1, n):
    if str[i - 1] == str[i]:
        is_p[i - 1][i] = 1

for i in range(3, n + 1):
    for start in range(n - i + 1):
        end = start + i - 1
        if str[start] == str[end] and is_p[start + 1][end - 1]:
            is_p[start][end] = 1

for end in range(i):
    for start in range(end + 1):
        if is_p[start][end]:
            dp[end] = min(dp[end], dp[start - 1] + 1)
        else:
            dp[end] = min(dp[end], dp[end - 1] + 1)

print(dp[n - 1])