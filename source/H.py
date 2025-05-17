l, r = map(int, input().split())

if l + 1 == r:
    print(l ^ r)
else:
    ans = 1
    while ans <= (r - l):
        ans *= 2
    while True:
        ans //= 2
        if (ans & l) == 0:
            break
        tmp = l + (ans - ((ans - 1) & l))
        if ans <= r - tmp:
            break
    print(ans)