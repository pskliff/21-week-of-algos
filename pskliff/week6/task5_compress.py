def remake(arr):
    res = ''

    arr = sorted(arr)
    start = arr[0]
    end = 0
    for i in range(len(arr) - 1):
        if arr[i + 1] != arr[i] + 1:
            end = arr[i]
            if start != end:
                res += str(start) + "-" + str(end)
            start = arr[i + 1]
    return res

print(remake([13, 1,2,3,4,10,11, 1]))

