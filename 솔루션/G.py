import sys
import bisect

input = sys.stdin.readline

n, m = map(int, input().split())
v = []
for _ in range(n):
    a, b = map(int, input().split())
    v.append(a * a + b * b)

r = int(input())
v.sort()

ans = 2
mx = 0
pre = r * r
cur = pre * 2

for i in range(2, m + 1):
    cnt = bisect.bisect_left(v, cur) - bisect.bisect_left(v, pre)
    if cnt > mx:
        mx = cnt
        ans = i
    pre = cur
    cur = pre + r * r

print(ans)
