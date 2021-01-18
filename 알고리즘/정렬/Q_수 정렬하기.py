import sys
input = sys.stdin.readline
k = []
N = int(input())
for _ in range(N):
    a = int(input())
    k.append(a)
k = sorted(k)
for i in k:
    print(i)

