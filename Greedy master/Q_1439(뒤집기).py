n = list(input())
prev = n[0]
result= []
count = 0
# 0번 인덱스 기준
for i in n:
    if i != prev and i != n[0]:
        count += 1
    prev = i
result.append(count)

# 0번 인덱스 기준으로 뒤짚기
count = 0
for i in n:
    if i =='0':
        i =='1'
    else:
        i == '0'
prev = n[0]
count +=1
for i in n:
    if i != prev and i != n[0]:
        count += 1
    prev = i
result.append(count)
result.sort()
print(result[0])

    
