#N장의 카드 수 를 입력하고, 이 중의 3장의 카드의 합이 M을 넘지 않는 MAX 수를 만들고 입력.
import sys
plus = []
N, M = map(int, sys.stdin.readline().split())
arr = list(map(int,sys.stdin.readline().split(' ')))

    
for i in range(0,N-2):
    for k in range(i+1,N-1):
        for q in range(k+1,N):
            if arr[i]+arr[k]+arr[q]>M:
                continue
            else:
                plus.append(arr[i]+arr[k]+arr[q])
plus.sort()
print(plus[-1])
    
