import sys
T = int(sys.stdin.readline())
result = []
for _ in range(T):
    N = int(sys.stdin.readline())
    cor = []
    for _ in range(N):
        a = list(map(int, sys.stdin.readline().split(' ')))
        cor.append(a)
    cor.sort()
    count = 0
    prev = 9999999
    for k in cor:
        fir, sec = k
        if sec < prev:
            count += 1
            prev = sec
    result.append(count)
for i in result:
    print(i)



        
