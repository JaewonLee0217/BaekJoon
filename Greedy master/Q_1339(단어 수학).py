#
k = []
N = int(input())
for _ in range(N):
    a = input()
    k.append(a)
trans = []
a= [0 for i in range(26)]
for i in range(len(k)):
    b = list(k[i])
    trans.append(b)
for i in trans:
    li = len(i)
    for j in range(li):
        a[ord(i[j]) - ord('A')] += 10 ** (li - j - 1)
a.sort(reverse=True)
result, cnt = 0,9
for i in a:
    result +=cnt*i
    cnt-=1
print(result)


