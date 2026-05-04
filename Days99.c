target = int(input())
n = int(input())
position = list(map(int, input().split()))
speed = list(map(int, input().split()))

cars = sorted(zip(position, speed), reverse=True)

stack = []

for pos, spd in cars:
    time = (target - pos) / spd
    stack.append(time)

    if len(stack) >= 2 and stack[-1] <= stack[-2]:
        stack.pop()

print(len(stack))
