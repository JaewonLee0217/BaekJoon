#1,2,3을 이용해서 더하여 해당 입력 숫자를 만드는 방법 수.

#첫번째 줄은 테스트 케이스의 개수
#다음 줄은 정수n이 주어진다.

T = int(input())
box = [1,2,4]
for i in range(3,11):
    box.append(box[i-3]+box[i-2]+box[i-1])
for i in range(T):
    n = int(input())
    print(box[n-1])
    
