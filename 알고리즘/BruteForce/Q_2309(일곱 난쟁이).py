import sys
k = []
for i in range(9):
    t = int(sys.stdin.readline())
    k.append(t)
ksum = sum(k)
for i in range(0,8):
    for j in range(1,9):
        if (ksum-k[i]-k[j]) ==100:
            k.remove(k[i])
            k.remove(k[j])
            k.sort()
            break
for i in range(len(k)):
    print(k[i])
            
        
    
