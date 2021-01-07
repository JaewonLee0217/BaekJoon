import sys
input = sys.stdin.readline
N = int(input())
result = []
k = list(map(int,input().split(' ')))
count = 0
keep = 0
for i in k:
    if i > keep:
        count = 0
        keep = i
    else:
        count += 1
    result.append(count)
print(max(result))

        
