from math import sqrt
sq=[49,4,16,25,81,36]
list_of_sq=list(filter(lambda x: True if sqrt(x)%2!=0 else False,sq))
for i in list_of_sq:
    print(i)