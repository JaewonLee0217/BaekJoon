#0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데
#필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.

N, M = map(int, input().split())
A = [list(map(int,input())) for _ in range(N)]
B = [list(map(int,input())) for _ in range(N)]


def convert(x,y):
    for i in range(x,x+3):
        for j in range(y,y+3):
                A[i][j] =1- A[i][j]

def checking():
    for a in range(N):
        for b in range(M):
            if A[a][b] !=B[a][b]:
                return 0
    return 1

count=0
for i in range(0,N-2):
    for j in range(0,M-2):
        if A[i][j] != B[i][j]:
            convert(i,j)
            count +=1
if checking():
    print(count)
else:
    print(-1)
            
