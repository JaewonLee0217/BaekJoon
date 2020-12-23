n = int(input())
count = 0
rest = 1000 - n
if rest > 0:
    while (rest//500) > 0:
        rest = rest - 500
        count = count + 1

    while (rest//100) > 0:
        rest = rest - 100
        count = count + 1
        
    while (rest//50) > 0:
        rest = rest - 50
        count = count + 1

    while (rest//10) > 0:
        rest = rest - 10
        count = count + 1
        
    while (rest//5) > 0:
        rest = rest - 5
        count = count + 1

    while (rest//1) > 0:
        rest = rest -1
        count = count + 1
print(count)

