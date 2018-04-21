def bin_search(ls, x, i, j):
    while abs(j - i) > 1:
        sep = (i + j) // 2
        if ls[sep] > x:
            j = sep
        else:
            i = sep
    return ls[i] == x or ls[j] == x


N, K = tuple(map(int, input().split()))
ls = list(map(int, input().split()))
target = map(int, input().split())
for x in target:
    print("YES" if bin_search(ls, x, 0, len(ls) - 1) else "NO")
