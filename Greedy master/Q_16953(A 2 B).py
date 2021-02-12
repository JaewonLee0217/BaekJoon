import sys
input = sys.stdin.readline().strip

a,b = map(int, input().split())
count = 1

while True:
    if a == b:
        break
    elif a > b:
        count = -1
        break
    elif (b%10) == 1:
        b = b//10
        count += 1
    elif (b%2) == 0:
        b = b//2
        count +=1
    else:
        count = -1
        break
print(count)
