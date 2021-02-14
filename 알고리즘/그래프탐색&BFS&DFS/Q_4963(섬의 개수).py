import sys
input = sys.stdin.readline

#우, 좌, 하, 상, 우하, 좌하, 우상, 좌상 8방향 dx dy로 정의.
dx = [1,-1,0,0,1,-1,1,-1]
dy = [0,0,-1,1,-1,-1,1,1]
#땅이 랜드일 때 BFS실행.
def bfs(i,j):
    s[i][j] = 0
    queue = [[i,j]]
    while queue:
        a,b = queue[0][0],queue[0][1]
        del queue[0]
        #현재 위치 a,b에서 dx dy방향 더해서 위치 변경
        for k in range(8):
            x = a + dx[k]
            y = b + dy[k]
            #world범위안에 있고 숫자가 1인거, 랜드일 경우 0으로 바꿔주고 큐에 넣어줌.
            if 0<=x<h and 0<=y<w and s[x][y] == 1:
                s[x][y] = 0
                queue.append([x,y])    
            
while True:
    w,h = map(int, input().split())
    #0이 두개 주어졌을 때
    if w == 0 and h == 0:
        break
    s = []
    count = 0
    for _ in range(h):
        a = list(map(int, input().split()))
        s.append(a)
    for i in range(h):
        for j in range(w):
            if s[i][j] == 1:
                bfs(i,j)
                count += 1
    print(count)
            
        
        
            

