import sys
input = sys.stdin.readline

n, q = map(int, input().split())

v = [[] for _ in range(n+1)]

p = list(range(n+1))

for i in range(1, n+1):
    v[i].append(i)


def Find(x):
    if p[x] != x:
        p[x] = Find(p[x])
    return p[x]

def Union(a, b):
    a = Find(a)
    b = Find(b)
    if a == b:
        return False
    if len(v[a]) < len(v[b]):
        a, b = b, a
    v[a].extend(v[b])
    p[b] = a
    v[a].sort(reverse=True)
    while len(v[a]) > 20:
        v[a].pop()
    return True

for _ in range(q):
    t, a, b = map(int, input().split())
    if t == 1:
        Union(a, b)
    else:  
        f = Find(a)
        if len(v[f]) < b:
            print(-1)
        else:
            print(v[f][b-1])
