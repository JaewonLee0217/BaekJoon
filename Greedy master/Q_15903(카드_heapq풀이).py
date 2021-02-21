import sys
import heapq
input = sys.stdin.readline

n,m = map(int, input().split())

card = list(map(int,input().split()))
heapq.heapify(card)

for i in range(m):
    card1 = heapq.heappop(card)
    card2 = heapq.heappop(card)

    heapq.heappush(card, card1+card2)
    heapq.heappush(card, card1 + card2)
print(sum(card))
