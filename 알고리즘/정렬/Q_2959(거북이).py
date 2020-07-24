#거북이가 만들 수 있는 가장 큰 직사각형을 계산하는 프로그램을 작성

#Input: 첫째 줄에 거북이가 생각한 네 양의 정수 A, B, C, D가 주어진다. (0 < A, B, C, D < 100)
#Output: 첫째 줄에 거북이가 만들 수 있는 가장 큰 직사각형의 면적을 출력한다.
arr=[]
A,B,C,D = map(int,input().split())
arr.append(A)
arr.append(B)
arr.append(C)
arr.append(D)
arr.sort()
dist1 = arr[-1]-arr[-2]
dist2 = arr[1]-arr[0]
a= arr[3]-dist1
b= arr[1]-dist2
print(a*b)
