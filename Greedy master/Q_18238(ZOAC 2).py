K = input()
a= []
for i in K:
    a.append(i)
count = 0
t=0
now = 'A'
for i in range(len(a)):
    num = abs(ord(a[i])-ord(now))
    now = a[t]
    if num > 13:
        num = 26-num
    count +=num
    t += 1
    
print(count)
