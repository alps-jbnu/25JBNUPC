n = int(input())
dp = [[0] * 7 for _ in range(n)]
arr=list(map(int,input().split()))

for i in range(n):
    a=arr[i]
    if i == 0:
        if a == 0:
            dp[0][1] = 1
        dp[0][0] = 3
        dp[0][6] = 3
        continue

    if a == 0:  # sunny
        dp[i][0] = dp[i-1][6] + 3
        for j in range(1, 6):
            if dp[i-1][j-1] == 0:
                continue
            dp[i][j] = dp[i-1][j-1] + j
        if dp[i-1][5]:
            dp[i][5] = max(dp[i][5], dp[i-1][5] + 5)
    elif a == 1:  # rainy
        dp[i][0] = dp[i-1][6] + 3

    dp[i][6] = max(dp[i])

print(dp[n-1][6])
