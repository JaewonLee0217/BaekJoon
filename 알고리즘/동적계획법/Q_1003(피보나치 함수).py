#테스트 케이스를 출력받고 0이 출력되는 횟수, 1이 출력되는 횟수를 공백으로 구분해서 출력.
#피보나치 함수 fin(N)
import sys
n = int(sys.stdin.readline())
for i in range(n):
    t = int(sys.stdin.readline())  
    zero = 1
    one = 0
    temp = 0 # 초기화
    for _ in range(t):
        temp = one
        one += zero
        zero = temp
    print(str(zero)+' '+str(one))
    


