#DFS는 Stack을 이용, BFS는 Queue를 이용.
N, M  = map(int, input().split(' '))
maze = []
v_maze = [[0 for _ in range(M)] for _ in range(N)]
v_maze[0][0] =1 
for _ in range(N):
    temp = input()
    row = []
    for i in temp:
        row.append(int(i))
    maze.append(row)
que = []
que.append([0,0])
while True:
    if len(que) == 0:
        break

    a,b = que.pop(0)

    if a-1>=0:
        if maze[a-1][b] ==1 and v_maze[a-1][b] == 0:
            que.append([a-1,b])
            v_maze[a-1][b] += v_maze[a][b] + 1
    if b+1<len(maze[0]):
        if maze[a][b+1] ==1 and v_maze[a][b+1] == 0:
            que.append([a,b+1])
            v_maze[a][b+1] += v_maze[a][b] + 1
    if a+1<len(maze):
        if maze[a+1][b]==1 and v_maze[a+1][b] == 0:
            que.append([a+1,b])
            v_maze[a+1][b] += v_maze[a][b] + 1
    if b-1 >=0:
        if maze[a][b-1] ==1 and v_maze[a][b-1] == 0:
            que.append([a,b-1])
            v_maze[a][b-1] += v_maze[a][b] + 1
print(v_maze[N-1][M-1])
        

        
