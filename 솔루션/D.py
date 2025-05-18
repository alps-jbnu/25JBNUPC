n = int(input())
t = input()

if t[-1] == '1':
    print(0)
else:
    ans = 1
    mod = int(1e9 + 7)

    for i in range(n - 1):
        if t[i] == '0':
            ans *= 2
        ans %= mod

    print(ans)