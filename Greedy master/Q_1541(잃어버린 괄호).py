#n개의 숫자 조합의 연산식이 나오고, 괄호는 연산 순서를 지정.
import sys

n = sys.stdin.readline().split('-')

k= []
for i in n:
    int_n= 0
    sum_n=i.split('+')
    for j in sum_n:
        int_n +=int(j)
    k.append(int_n)
base = k[0]
for i in range(1,len(k)):
    base -=k[i]
print(base)

