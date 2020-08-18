#첫째 줄에 삼각형의 크기 n을 받아서 둘째줄 부터 n+1번째 줄까지 정수 삼각형을 그리고 경로 안의 합의 최대를 출력.

n = int(input())
result = []

side=2 # 삼각형이 되려면 최소 2*2이니까 
for i in range(n):
    result.append(list(map(int,input().split())))
for i in range(1,n): # 맨 위의 값은 무조건 더해야 하므로 1부터 시작.
    for j in range(side):
        if j==0: #즉, 가장 왼쪽 줄일때,
            result[i][j] +=result[i-1][j]
        elif i==j: # 가장 오른 쪽 줄일 때
            result[i][j] +=result[i-1][j-1]
        else: # 가운데
            result[i][j] +=max(result[i-1][j],result[i-1][j-1])
    side+=1 # 다음 줄은 1증가하므로
print(result)
