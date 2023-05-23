from itertools import compress
#using generator
def getEven(ran):
    num=2
    while ran>0:
        yield num
        num+=2
        ran=ran-1
def getOdd(ran):
    num=1
    while ran>0:
        yield num
        num+=2
        ran=ran-1

x=iter(getEven(10))
y=iter(getOdd(10))
print("First 10 even numbers are::")
for i in x:
    print(i)
print()
print("First 10 odd numbers are::")
for i in y:
    print(i)

#using compress
print("Printing using compress")
int_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20]
list_even =[True if x%2==0 else False for x in int_list]
list_odd=[True if x%2!=0 else False for x in int_list]
print("Even numbers are::")
for i in compress(int_list,list_even):
    print(i)
print("Odd numbers are::")
for i in compress(int_list,list_odd):
    print(i)