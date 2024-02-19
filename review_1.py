import sys
input = sys.stdin.readline

num = int(input())
k = list(map(int, input().split(' ')))
a = min(k)
b = max(k)
N = a *b
print(N)
