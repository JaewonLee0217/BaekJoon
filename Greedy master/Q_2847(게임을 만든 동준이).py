import sys
input = sys.stdin.readline

n = int(input())
res=[]
for i in range(n):
    k = int(input())
    res.append(k)
j=n-2
count = 0
while j >=0:
    if res[j] >= res[j+1]:
        res[j]-=1
        count +=1
    else:
        j-=1
print(count)
    
