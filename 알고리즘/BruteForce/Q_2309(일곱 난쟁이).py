import sys
k = []
for i in range(9):
    t = int(sys.stdin.readline())
    k.append(t)
ksum = sum(k)-100
for i in range(0,8):
    for j in range(i+1,9):
        if ksum ==(k[i]+k[j]):
            a=k[i]
            b=k[j]
            break


k.remove(a)
k.remove(b)
k.sort()
for i in range(len(k)):
    print(k[i])
            
        
    
