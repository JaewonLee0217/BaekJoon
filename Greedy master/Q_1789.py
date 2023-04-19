N = int(input())
ans = 0
i = 1
counting = 0
#i+1을 몇까지 반복해서 돌릴꺼냐
while True:
    if ans <= N:
        ans += i
        i += 1
        counting += 1
    else:
        counting -= 1
        break

print(counting)
