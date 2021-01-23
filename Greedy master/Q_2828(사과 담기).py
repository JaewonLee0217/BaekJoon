#N,M,J
import sys
input = sys.stdin.readline
N,M = map(int, input().split(' '))
J = int(input())
k = []
start = 1
end = M
ans = 0
for _ in range(J):
    a = int(input())
    k.append(a)
for i in k:
    if i < start:
        ans += (start - i)
        start = i
        end = i + M-1
    elif i > end:
        ans += (i-end)
        end = i
        start = end - M + 1
print(ans)
#만약 처음 위치가
