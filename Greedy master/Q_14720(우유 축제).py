import sys
input = sys.stdin.readline
zero = True
one = False
two = False
n = int(input())
count = 0
k = list(map(int,input().split(' ')))

for i in k:
    if zero:
        if i == 0:
            count += 1
            one = True
            zero = False
    elif one:
        if i == 1:
            count += 1
            two = True
            one = False
    elif two:
        if i == 2:
            count += 1
            zero = True
            two = False
print(count)
        
