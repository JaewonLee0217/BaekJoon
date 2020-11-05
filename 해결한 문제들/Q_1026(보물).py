##S의 최솟값을 출력하는 프로그램을 작성하시오

N = int(input())
list_a = list(map(int,input().split(" ")))
list_b = list(map(int,input().split(" ")))
A = sorted(list_a)
rB = sorted(list_b,reverse = True)
S = 0
for i in range(N):
    S = S+ A[i]*rB[i]
print(S)
    
    
