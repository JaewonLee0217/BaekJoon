#정점 개수 N, 간선 개수 M, 시작 정점 V를 입력받아 첫 째줄 DFS를 수행한 결과, 두번째
#줄에는 BFS를 수행한 결과를 출력하시오.

def DFS(num):
    print(num,end=' ') #방문하면 그 수를 출력
    visited[num] =1
    for i in range(N+1):
        if visited[i] ==0 and adlist[num][i]==1:
            DFS(i)

def BFS(num):
    result = [num]
    visited[num] = 0
    while(result):
        num = result[0]
        print(num,end=' ')
        del result[0]
        for i in range(N+1):
            if visited[i]==1 and adlist[num][i]==1:
                result.append(i)
                visited[i]=0
    
    
    

import sys
N,M,V = map(int,sys.stdin.readline().split())
adlist = [[0]*(N+1) for i in range(N+1)]
visited = [0 for i in range(N+1)]
# matrix만들어주고
for i in range(M):
    a,b = map(int, sys.stdin.readline().split())
    adlist[a][b] = 1
    adlist[b][a] = 1
    #adlist에 인접행렬들을 표로 구현시키고

DFS(V)
print()
BFS(V)
