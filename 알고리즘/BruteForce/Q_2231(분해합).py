import sys
input = sys.stdin.readline

N = int(input())
low = 0

#무차별로 대입할 생성자 low_n을 분해해서 분해합을 만든다
#198이면 1,9,8로 분해 해서 int로 변환
#원래값과 분해한 수들의 합을 더한다.
def get_devided_num(low_n):
    e = list(map(int, str(low_n)))
    dn = low_n + sum(e)

    return dn
#분해합을 구해서 주어진 분해합과 같지 않는 다면 
while get_devided_num(low) != N:
    #생성자가 없을 경우(1씩 더해가며 분해합에 도달했을 경우)
    if low == N:
        low = 0
        break
    else:
        low += 1

print(low)
