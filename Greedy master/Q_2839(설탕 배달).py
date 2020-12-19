#5a +3b로 나누어 떨어져야 한다

N = int(input())
count = 0
b= 1
if N%5 ==0:
    print(N//5)
else:
   while True:      
       N = N -3
       if N<0:
           print(-1)
           break
       if N%5==0:
           print(N//5 + b)
           break
       else:
           b= b+1
           continue

        
        
    
