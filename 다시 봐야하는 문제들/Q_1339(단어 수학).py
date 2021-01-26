#
N = int(input())
k=[]
for _ in range(N):
    a = input()
    k.append(a)
res = []
for i in range(len(k)):
    b = list(k[i])
    res.append(b)
alpha = [0 for i in range(26)]
for i in res:
    li = len(i)
    for j in range(li):
        alpha[ord(i[j])-ord('A')] += 10**(li-j-1)
alpha.sort(reverse= True)
result, cnt = 0,9
for i in alpha:
    result += cnt*i
    cnt -=1
print(result)
