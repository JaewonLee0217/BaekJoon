import sys
input = sys.stdin.readline

a,b = map(int, input().split())
card  = list(map(int,input().split()))

for i in range(b):
    card = sorted(card)
    cover = card[0] + card[1]
    card[0] = cover
    card[1] = cover

print(sum(card))
