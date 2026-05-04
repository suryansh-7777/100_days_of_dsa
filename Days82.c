def lower_bound(arr, x):
    l, r = 0, len(arr)
    while l < r:
        mid = (l + r) // 2
        if arr[mid] < x:
            l = mid + 1
        else:
            r = mid
    return l

def upper_bound(arr, x):
    l, r = 0, len(arr)
    while l < r:
        mid = (l + r) // 2
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid
    return l

n = int(input())
arr = list(map(int, input().split()))
x = int(input())

print(lower_bound(arr, x), upper_bound(arr, x))
