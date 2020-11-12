#첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)

#둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)

i = int(input())
ilist = [0]+ list(map(int,input().split()))
count = [0]*(i+1) # N개 중의 최댓값 배열

count[1] = ilist[1]
for a in range(2,i+1):
    for b in range(1,a+1):
        if count[a]<count[a-b]+ilist[b]:
            count[a] = count[a-b] + ilist[b]
print(count[i])
