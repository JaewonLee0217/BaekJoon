import sys
from collections import deque
input = sys.stdin.readline

def bfs(m,n,farm):
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    count = -1

    #메인 식에서 1인 것만 deque에 담았으로 그에 대한 연산만 실행.
    while deque:
        count += 1

        for _ in range(len(deque)):
            a,b = deque.popleft()
            for i in range(4):
                x = a + dx[i]
                y = b + dy[i]
                if 0<=x<n and 0<=y<m and farm[x][y] == 0:
                    farm[x][y] = 1
                    deque.append([x,y])
    for i in farm:
        if 0 in i:
            return -1
    return count
            
                

m,n = map(int, input().split())
deque = deque()
farm = []
for i in range(n):
    row = list(map(int,input().split()))
    for j in range(m):
        if row[j] == 1:
            deque.append([i,j])
    farm.append(row)

answer = bfs(m,n,farm)
print(answer)
