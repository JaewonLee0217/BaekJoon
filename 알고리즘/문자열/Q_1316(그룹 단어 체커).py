#단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

#Input : 첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다.
#둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

#Output : 첫째 줄에 그룹 단어의 개수를 출력한다.
#그 string을 어떻게 구분해서 읽을까.

num = int(input())

count =0
for i in range(num):
    str = input()
    for a in range(len(str)):
        if a != len(str)-1:
            if str[a]==str[a+1]:
                pass
            elif str[a] in str[a+1:]:
                break
        else:
            count+=1
print(count)
        
    
