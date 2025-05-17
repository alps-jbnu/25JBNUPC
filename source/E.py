import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

def main():
    m = int(input())
    data = []
    while len(data) < m:
        data.extend(map(int, input().split()))
    arr = [x - 1 for x in data]

    vis = [0] * m
    cnt = 0      
    ans = -1     
    mm = 0       

    def dfs(u):
        nonlocal cnt, ans, mm
        cnt += 1
        vis[u] = cnt
        v = arr[u]
        if vis[v]:
            if vis[v] < mm:
                return
            ans = max(ans, vis[u] - vis[v] + 1)
        else:
            dfs(v)

    for i in range(m):
        if vis[i]:
            continue
        dfs(i)
        mm = cnt + 1

    print(ans)

if __name__ == "__main__":
    main()