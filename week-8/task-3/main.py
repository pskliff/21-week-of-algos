def f(v, d, ls, all_dist):
    a, b = 0, ls[-1][1]
    time = 0
    count = 0
    while abs(a - b) > 0.1:
        c = (a + b) / 2
        count = 0
        time = c
        for i in ls[:-1]:
            time += i[0] / v
            if time >= i[1]:
                count += 1
                time += d
        time += ls[-1][0] / v
        if int(time) + 1 == ls[-1][1]:
            res = int(c + time + all_dist / v + d * (len(ls) - count)) + 1
            return "%02d:%02d" % (res // 60, res % 60)
        elif int(time) + 1 < ls[-1][1]:
            a = c
        else:
            b = c
    res = int(a + time + d * (len(ls) - count) + all_dist / v) + 1
    return "%02d:%02d" % (res // 60, res % 60)


v, d = map(int, input().split())
N = int(input())
ls = []
prev = 0
for i in range(N):
    t = tuple(map(lambda x: int(x) if len(x.split(':')) == 1 else int(x.split(':')[0]) * 60 + int(x.split(':')[1]),
                  input().split()))
    ls.append(tuple([t[0] - prev, t[1]]))
    prev = t[0]
print(f(v, d, ls, prev))
