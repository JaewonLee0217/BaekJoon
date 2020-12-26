#55-50+40, -35 최소값만들도록 괄호치기

import sys
k=[]
n = sys.stdin.readline().split('-')
for i in n:
    count = 0
    rr=i.split('+')
    for j in rr:
        count += int(j)
    k.append(count)
sum_first = k[0]
for i in range(1,len(k)):
    sum_first -= k[i]
print(sum_first)
    
