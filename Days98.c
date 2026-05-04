n = int(input())
intervals = [tuple(map(int, input().split())) for _ in range(n)]

intervals.sort()

merged = [intervals[0]]

for curr in intervals[1:]:
    last = merged[-1]

    if curr[0] <= last[1]:
        merged[-1] = (last[0], max(last[1], curr[1]))
    else:
        merged.append(curr)

for i in merged:
    print(i[0], i[1])
