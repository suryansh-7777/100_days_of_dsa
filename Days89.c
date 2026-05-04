def is_possible(arr, n, m, max_pages):
    students = 1
    pages = 0

    for i in range(n):
        if arr[i] > max_pages:
            return False
        if pages + arr[i] > max_pages:
            students += 1
            pages = arr[i]
            if students > m:
                return False
        else:
            pages += arr[i]

    return True

n, m = map(int, input().split())
arr = list(map(int, input().split()))

l, r = max(arr), sum(arr)
ans = r

while l <= r:
    mid = (l + r) // 2
    if is_possible(arr, n, m, mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)
