#세 가지 연산이 있다(Dynamic Programming)
#1.x가 3으로 나누어 떨어지면, 3으로 나눈다.
#2.X가 2로 나누어 떨어지면, 2로 나눈다.
#3.1을 뺀다.
#정수 한 개를 입력 받아 1로 만들고 연산을 사용한 횟수를 출력.
N = int(input())
arr = [0]*(N+1)
for i in range(2,N+1):
    arr[i] = arr[i-1]+1
    if i%2==0 and arr[i]>arr[i//2]+1:
        arr[i]=arr[i//2]+1
    if i%3==0 and arr[i]>arr[i//3]+1:
        arr[i]=arr[i//3]+1
print(arr[N])
        
        
