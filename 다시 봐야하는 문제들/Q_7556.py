##2번 유저의 소스 코드 첫번째 줄 수정 commit!!
import sys
input = sys.stdin.readline

m,n = map(int, input().split())
pmap = []
#첫쨰날 ~ 끝까지 토마토 수
pcount = []
count = 0
def mapcount(pmap):
    a= 0
    for i in range(n):
        for j in range(m):
            a += pmap[i][j]
    return a
    
for _ in range(n):
    a = list(map(int,input().split()))
    pmap.append(a)
dx = [1,-1,0,0]
dy = [0,0,1,-1]
def bfs(a,b):
    for i in range(4):
        x = a + dx[i]
        y = b + dy[i]
        if 0<=x<n and 0<=y<m and pmap[x][y] == 0:
            pmap[x][y] = 1
        
pcount.append(mapcount(pmap))
k= 0
q= []
w = []
while True:
    #하루가 지나고
    for i in range(n):
        for j in range(m):
            if pmap[i][j] == 1:
                q.append(i)
                w.append(j)
    for e in range(len(q)):
        bfs(q[e],w[e])
    
    #count += 1
    pcount.append(mapcount(pmap))
    if pcount[k] == pcount[k+1]:
        break
    k += 1
for i in pmap:
    if 0 in i:
        k = -1
        break
    else:
        pass     
print(k)
