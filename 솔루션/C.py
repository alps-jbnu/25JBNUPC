n, m = map(int, input().split())

ans = 0
mn = 100000005

for i in range(max(n, m), min(n, m) - 1, -1):
    a = abs(i - n)
    b = abs(i - m)
    num = max(a * 3, b) + i - 1
    if mn > num:
        ans = i
        mn = num

print(mn)
