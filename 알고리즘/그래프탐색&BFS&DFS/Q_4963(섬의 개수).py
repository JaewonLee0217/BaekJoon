import sys
input = sys.stdin.readline

#8방향 설정
dx = [1,-1,0,0,1,1,-1,-1]
dy = [0,0,1,-1,-1,1,-1,1]

def bfs(i,j):
    s[i][j] = 0
    queue = [[i,j]]
    #아래 로직에서 인접 섬이 있으면 queue에 추가할 것임.
    while queue:
        #현재 연산지점을 큐에서 뽑아서 temp변수인 a,,b에 할당
        a,b = queue[0][0],queue[0][1]
        del queue[0]
        for d in range(8):
            x = a + dx[d]
            y = b + dy[d]
            #8방향에 인접 섬이 있는지 검사하고 있으면 0대입하고 큐에 담아주고
            if 0<=x<h and 0<=y<w and s[x][y]==1:
                s[x][y] = 0
                queue.append([x,y])
        
        

while True:
    w,h = map(int, input().split())
    if w==0 and h == 0:
        break
    s = []
    count = 0 
    for _ in range(h):
        a = list(map(int,input().split()))
        s.append(s)
    for i in range(h):
        for j in range(w):
            if s[i][j] == 1:
                bfs(i,j)
                count +=1
    print(count)
        
            

