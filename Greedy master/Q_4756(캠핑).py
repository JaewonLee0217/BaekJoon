import sys
input = sys.stdin.readline
r_ans = []
L = 9999
P = 9999
V = 9999
while True:
    L, P, V = map(int, input().split(' '))
    if L == 0:
        break
    a = V//P
    ans = L * a
    if L <= V%P :
        ans += L
    else:
        ans += V%P
    r_ans.append(ans)
    ans = 0
for i in range(1,len(r_ans)+1):
    print("Case {}: {}".format(i,r_ans[i-1]))
    
                  
