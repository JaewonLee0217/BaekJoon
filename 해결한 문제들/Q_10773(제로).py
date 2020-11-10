K = int(input())
klist = []
for i in range(K):
    a = int(input())
    if a==0:
        klist.pop()
    else:
        klist.append(a)
ksum = sum(klist)
print(ksum)
    
