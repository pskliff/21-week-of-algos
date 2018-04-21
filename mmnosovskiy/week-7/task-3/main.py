def bin_search(ls, x, i, j):
    res = []
    while abs(j - i) > 1:
        sep = (i + j) // 2
        if ls[sep] >= x:
            j = sep
        else:
            i = sep
    if ls[i] == x:
        res.append(i)
    elif ls[j] == x:
        res.append(j)
    else:
        return [0]
    i = 0
    j = len(ls) - 1
    while abs(j - i) > 1:
        sep = (i + j) // 2
        if ls[sep] > x:
            j = sep
        else:
            i = sep
    if ls[j] == x:
        res.append(j)
    else:
        res.append(i)
    return res


N, K = tuple(map(int, input().split()))
ls = list(map(int, input().split()))
target = map(int, input().split())
for x in target:
    res = bin_search(ls, x, 0, len(ls) - 1)
    print(' '.join(map(lambda x: str(x + 1), res)) if len(res) > 1 else '0')
