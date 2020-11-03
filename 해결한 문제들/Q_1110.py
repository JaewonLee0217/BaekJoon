#사이클 문제

N = int(input())
num = N
count = 1
while True:
    a= int(num/10)
    b= num%10
    c = a+b
    
    new1=c%10
    newN=(10*b)+new1
    if newN == N:
        break
    else:
        count = count +1
        num = newN
        continue
print(count)
