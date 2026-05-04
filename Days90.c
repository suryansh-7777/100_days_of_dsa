def is_possible(arr, n, k, max_time):
    painters = 1
    total = 0

    for i in range(n):
        if arr[i] > max_time:
            return False
        if total + arr[i] > max_time:
            painters += 1
            total = arr[i]
            if painters > k:
                return False
        else:
            total += arr[i]

    return True

n, k = map(int, input().split())
arr = list(map(int, input().split()))

l, r = max(arr), sum(arr)
ans = r

while l <= r:
    mid = (l + r) // 2
    if is_possible(arr, n, k, mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)
