arr = [[0] * 10 for _ in range(10)]
f = [1, 1] + [0] * 18

for i in range(2, 20):
    f[i] = f[i - 1] * i

for i in range(8):
    arr[i] = list(map(int,input().split()))

ans = 0
for i in range(8):
    for j in range(8):
        ans += arr[i][j] * (f[i + j] // f[i] // f[j]) * (f[14 - i - j] // f[7 - i] // f[7 - j])

print(ans)

