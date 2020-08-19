#테스트 케이스를 출력받고 0이 출력되는 횟수, 1이 출력되는 횟수를 공백으로 구분해서 출력.
#피보나치 함수 fin(N)
import sys
a=0 # 0의 수 count
b=0 # 1의 수 count
arr = [] # 함수를 돌릴 때마다 리스트를 초기화해 주고 append함.
def fibonacci(n):
    
    
    if n==0:
        arr.append(0)
        return 0
    elif n==1:
        arr.append(1)
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)
    
    
k= []
T = int(sys.stdin.readline())
for i in range(T):
    t = int(sys.stdin.readline())
    k.append(t)
for i in range(T):    
    fibonacci(k[i])
    print(str(arr.count(0))+' '+str(arr.count(1)))
    arr=[]
    


