fun=lambda x: True if x%5==0 else False

list_num=list()
for i in range(51):
    if fun(i):
        list_num.append(i)

for i in list_num:
    print(i)