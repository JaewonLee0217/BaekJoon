k = input()
k = list(k)
i = 0
re = []
for i in range(len(k)):
    if k[i] == ']':
        break
    elif k[i] == '[' or k[i] == ',':
        pass
    else:
        re.append(int(k[i]))
print(re)
