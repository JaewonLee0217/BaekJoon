#알람시계
#설정한 시간보다 45분 일찍 맞추어 주는 알람 시계를 작성.

H,M = map(int,input().split())

if M>44:
    print(H,M-45)
elif M<45 and H>0:
    print(H-1,M+15)
else:
    print(23,M+15)
    
    
