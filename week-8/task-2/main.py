def side(w, h, n):
    a = int((w * h * n) ** .5 - 1)
    b = max(w, h) * n
    while abs(a - b) > 1:
        c = (a + b) // 2
        if (c // w) * (c // h) >= n:
            b = c
        else:
            a = c
    return b


w, h, n = map(int, input().split())
print(side(w, h, n))
