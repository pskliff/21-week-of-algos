def is_bipartite(graph):
    part = [-1] * n
    ok = True
    q = [0] * n
    for st in range(n):
        if part[st] == -1:
            h, t = 0, 0
            q[t] = st
            t += 1
            part[st] = 0
            while h < t:
                v = q[h]
                h += 1
                for to in graph[v]:
                    if part[to] == -1:
                        part[to] = 1 if part[v] == 0 else 0
                        q[t] = to
                        t += 1
                    else:
                        ok = ok and (part[to] != part[v])
    return ok


g = []
n = int(input())
for i in range(n):
    g.append(list(map(int, input().split())))
print("YES" if is_bipartite(g) else "NO")
