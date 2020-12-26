import sys
n= int(sys.stdin.readline())
l = []
last = []
for _ in range(n):
    k = int(sys.stdin.readline())
    l.append(k)
l.sort()
for i in range(n):
    w = l[i] * (n-i)
    last.append(w)
last.sort()
print(last[-1])
