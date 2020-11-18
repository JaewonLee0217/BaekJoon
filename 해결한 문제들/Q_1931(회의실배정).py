#첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다.
#둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데
#이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다.
#시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

N = int(input())
room = []
for _ in range(N):
    a,b = map(int,input().split())
    room.append([a,b])
#room = sorted(room, key=lambda a: a[0]) #시작 시간 기준으로 정렬
room = sorted(room, key=lambda a: a[1]) # 끝나는 시간 기준으로 정렬해준다. 하면 예를들어 23 4 편리하게 분리할 수 있다.
count = 0
last =0
for i,j in room:
    if i>=last:
        count+=1
        last = j
print(count)
    
