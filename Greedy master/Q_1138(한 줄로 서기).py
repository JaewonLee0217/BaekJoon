import sys
input = sys.stdin.readline

N = int(input())
k = list(map(int,input().split(' ')))
count = 0
r= [0] * N
for w in range(1,len(k)+1):
    temp = k[w-1]
    count = 0
    for i in range(N):
        if count == temp and r[i] == 0:
            r[i] = w
            break
        elif r[i] == 0:
            count += 1
for a in r:
    print(a,end=' ')
            
    
