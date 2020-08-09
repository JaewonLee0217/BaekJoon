from collections import deque
n, k = map(int, input().split())

MAX = 100001
dp = [MAX]*MAX
dp[k] = 0

queue = deque()
queue.append(k)

while queue:
    num = queue.popleft()

    if num ==n:
        print(dp[num])
        break
    if num < MAX-1 and dp[num+1] > dp[num]+1:
        dp[num+1] = dp[num]+1
        queue.append(num+1)

    if num>0 and dp[num-1]>dp[num]+1:
        dp[num-1] = dp[num]+1
        queue.append(num-1)

    if num%2==0:
        if dp[num//2] > dp[num]+1:
            dp[num//2] = dp[num]+1
            queue.append(num//2)
        

        
            
            
        
