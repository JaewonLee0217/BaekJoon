N = int(input())
list_a = list(map(int, input().split(" ")))
key = max(list_a)
ans = sum(list_a) - key
print(ans)

