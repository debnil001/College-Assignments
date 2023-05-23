def fibbo(count):
    a,b,c=0,1,0
    while count>0:
        yield c
        a=b
        b=c
        c=a+b
print("================================")
x=iter(fibbo(7))

for i in range(7):
    print(x.__next__())