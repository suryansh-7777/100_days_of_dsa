import heapq

n = int(input())
intervals = [tuple(map(int, input().split())) for _ in range(n)]

intervals.sort()

heap = []

for start, end in intervals:
    if heap and heap[0] <= start:
        heapq.heappop(heap)
    heapq.heappush(heap, end)

print(len(heap))
