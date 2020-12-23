import sys
n = int(sys.stdin.readline())
k = []
for _ in range(n):
    r = int(sys.stdin.readline())
    k.append(r)
# 각 경우에 대한 최댓값 비교를 위해 리스트 추가
list_min = []
for i in range(n):
    k.sort()
    min_a = k[i] * (n-i)
    list_min.append(min_a)
list_min.sort()
print(list_min[-1])

        
