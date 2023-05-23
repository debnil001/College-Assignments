def generatePrime(nums):
    for i in range(2,nums):
        for j in range(2,i):
            if i%j==0:
                break
        else:
            yield i   

x=generatePrime(100)

for i in x:
    print(i)