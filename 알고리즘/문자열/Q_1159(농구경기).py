a=[]
result=[]
kb=[]
#a선수 명단
N = int(input())

#N 선수의 수
for i in range(N):
    Fn = input()
    a.append(Fn[0])
    #첫글자 Fn[0]
for k in range(0,len(a)):
    if a.count(a[k])>=5:
        result.append(a[k])
        k = set(result)
        kb = list(k)
        kb.sort()
    
if not result:
            print("PREDAJA")
else:
    for i in kb:
        print(i,end='')
            
