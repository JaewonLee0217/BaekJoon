#n가지 종류의 동전이 있다.
#각각의 동전이 나타내는 가치는 다르다.
#이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
#그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다

n,k = map(int,input().split())
nlist=[]
nsum = 0
for i in range(n):
    nn = int(input())
    nlist.append(nn)
count = [0 for i in range(k+1)]
count[0] =1
for i in nlist:
    for j in range(i,k+1):
        if j-i>=0:
            count[j] +=count[j-i]
print(count[k])

#count배열을 만든다음에 1 들어갈때 , 2들어갈때 3=5들어갈때 해가주고 순차적으로 배열
#값을 늘려주는 개념.
