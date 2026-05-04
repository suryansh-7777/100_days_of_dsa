n = int(input())
arr = list(map(float, input().split()))

buckets = [[] for _ in range(n)]

for num in arr:
    index = int(num * n)
    buckets[index].append(num)

for b in buckets:
    b.sort()

result = []
for b in buckets:
    result.extend(b)

print(*result)
