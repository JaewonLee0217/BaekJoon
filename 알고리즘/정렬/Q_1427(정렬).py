import sys
input = sys.stdin.readline
ans = []
count = 0
N = list(input())
for i in range(len(N)-1):
    N[i] = int(N[i])
    ans.append(N[i])
ans = sorted(ans, reverse=True)
for i in range(len(ans)):
    count += ans[i]*10**(len(ans)-(i+1))
print(count)
