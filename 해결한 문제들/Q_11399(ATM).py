# 총 5명이 있고, P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 인 경우

ksum = 0
result = []
N = int(input())
person = list(map(int,input().split()))
K = sorted(person)
for i in range(N):
    ksum = ksum + K[i]
    result.append(ksum)
result1 = sum(result)
print(result1)
    
