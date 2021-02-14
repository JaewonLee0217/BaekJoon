#상근이가 가장 적은 종류의 비행기를 타고 모든 국가를 여행
#Input : 첫 번째 줄에는 테스트 게이스의 수 T(T<100)가 주지고
#테스트 케이스마다 첫번째 줄 국가수N, 비행기 종류M가 주어진다.
#이후 M개의 줄에 a와 b 쌍들이 입력된다. a와 b를 왕복하는 비행기가 있다는 것을 의미.

#Ouput : 테스트케이스마다 한 줄을 출력한다.

import sys
t = int(sys.stdin.readline())
for i in range(t):
    n, m = map(int, sys.stdin.readline().split())
    for j in range(m):
        a, b = map(int, sys.stdin.readline().split())
    print(n - 1)
        
