def bin_search(ls, x, i, j):
    while abs(j - i) > 1:
        sep = (i + j) // 2
        if ls[sep] > x:
            j = sep
        else:
            i = sep
    if ls[i] is x or ls[j] is x:
        return x
    if abs(ls[i] - x) > abs(ls[j] - x):
        return ls[j]
    else:
        return ls[i]


N, K = tuple(map(int, input().split()))
ls = list(map(int, input().split()))
target = map(int, input().split())
for x in target:
    print(str(bin_search(ls, x, 0, len(ls) - 1)))
