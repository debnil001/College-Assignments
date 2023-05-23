list_info=[('debnil','sarkardebnil01@gmail.com',11),('samiul','samiulalammolla@gmail.com',5),
           ('suman','gsuman984@gmail.com',21),('himangshu','himangshu2001@gmail.com',8),
           ('samrat','samratdas01@gmail.com',25),]

dict={}

for info in list_info:
    if info[2]>16:
        dict[info[0]]=info[1]

print("User over 16 years old are::")
for name,email in dict.items():
    print(name,"-->",email)