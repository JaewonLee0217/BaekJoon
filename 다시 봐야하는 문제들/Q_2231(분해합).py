#BruteForce

import sys
input = sys.stdin.readline

N = int(input())
num = 0

def creator(n):
    k = list(map(int, str(n)))
    return n + sum(k)

while creator(num) != N:
    if num == N:
        num = 0
        break
    else:
        num += 1
print(num)
