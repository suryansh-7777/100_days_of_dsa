def can_place(stalls, k, dist):
    count = 1
    last = stalls[0]

    for i in range(1, len(stalls)):
        if stalls[i] - last >= dist:
            count += 1
            last = stalls[i]
        if count >= k:
            return True
    return False

n, k = map(int, input().split())
stalls = list(map(int, input().split()))
stalls.sort()

l, r = 1, stalls[-1] - stalls[0]
ans = 0

while l <= r:
    mid = (l + r) // 2
    if can_place(stalls, k, mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)
