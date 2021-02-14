import sys
input = sys.stdin.readline


# 연결된 직전을 매트릭스상에 1로 표현
n = int(input())
net = int(input())
com = [[0]*n for _ in range(n)]

#전염 함수
def dfs(i):
    for k in range(n):
        if com[i][k] ==1:
            com[i][k] = 2
            dfs(k)
        
for _ in range(net):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    com[a][b] = 1
    com[b][a] = 1
#직접 1번 컴과 연결되어 있는 경우 2로 감염표시
dfs(0)

count = 0
for i in com:
    if i.count(2) !=0:
        count +=1
print(count-1)
