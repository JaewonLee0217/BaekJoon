import sys
input = sys.stdin.readline
k = []
N = int(input())
for _ in range(N):
    n = int(input())
    k.append(n)
k = sorted(k)
for i in k:
    print(i)
