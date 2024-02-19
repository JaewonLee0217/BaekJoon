#n이 주어졌을 때, 1부터 n까지 합

import sys
input = sys.stdin.readline

n = int(input())
count = 0
for i in range(n+1):
    count += i
print(count)
