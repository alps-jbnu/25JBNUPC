from collections import deque


def prep1(F):
    table = [([0] * len(F)) for _ in range(21)]
    table[0] = F

    for k in range(1, len(table)):
        for i in range(len(table[k])):
            x = table[k - 1][i]
            table[k][i] = table[k - 1][x]

    ret = list(range(len(F)))

    C = 1000000
    for k in range(len(table)):
        if (C & (1 << k)) == 0:
            continue

        for i in range(len(table[k])):
            ret[i] = table[k][ret[i]]

    return ret

def prep2(F):
    inv = [[] for _ in range(len(F))]
    for i in range(len(F)):
        inv[F[i]].append(i)

    ret = [-1] * len(F)
    cyclePos = [-1] * len(F)
    visited = [False] * len(F)

    for i in range(len(F)):
        if visited[i]:
            continue

        path = []
        current = i

        while not visited[current]:
            visited[current] = True
            path.append(current)
            current = F[current]

        cycle = []
        for j in range(len(path)):
            if path[j] == current:
                cycle = path[j:]
                break

        if len(cycle) == 0:
            continue

        Q = deque([cycle[0]])
        cyclePos[cycle[0]] = 0
        ret[cycle[0]] = cycle[1000000 % len(cycle)]

        while Q:
            v = Q.popleft()

            for next_node in inv[v]:
                if cyclePos[next_node] != -1:
                    continue
                cyclePos[next_node] = (cyclePos[v] + len(cycle) - 1) % len(cycle)
                ret[next_node] = cycle[(1000000 + cyclePos[next_node]) % len(cycle)]
                Q.append(next_node)

    return ret


if __name__ == "__main__":
    n, q = map(int, input().split())

    A = list(map(int, input().split()))
    F = list(map(int, input().split()))
    F = [x - 1 for x in F]

    F1e6 = prep2(F)
    A1e6 = [0] * n
    for i in range(n):
        A1e6[F1e6[i]] += A[i]

    for _ in range(q):
        query = input().split()

        if query[0] == "set":
            i = int(query[1]) - 1
            last = A[i]
            A[i] = int(query[2])

            A1e6[F1e6[i]] += A[i] - last

        if query[0] == "get":
            i = int(query[1]) - 1
            print(A1e6[i])
