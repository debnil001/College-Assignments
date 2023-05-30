import re
class NameExist(Exception):
	pass

class AgeInvalid(Exception):
	pass

class AgeUnder16(Exception):
	pass

class InvalidEmail(Exception):
	pass
list_info=[('debnil','sarkardebnil01@gmail.com',11),('samiul','samiulalammolla@gmail.com',5),
           ('suman','gsuman984@gmail.com',21),('himangshu','himangshu2001@gmail.com',8),
           ('samrat','samratdas01@gmail.com',25),]
def isValid(email):
	pattern="([A-Za-z0-9]+[.-_])*[A-Za-z0-9]+@[A-Za-z0-9-]+(\.[A-Z|a-z]{2,})+"
	if re.fullmatch(pattern,email):
		return True
	else:
		return False
	
name_set=set()
dict={}
for name,email,age in list_info:
	try:
		if name in name_set:
			raise NameExist
		if age<0:
			raise AgeInvalid
		if age<16:
			raise AgeUnder16
		if not isValid(email):
			raise InvalidEmail
		name_set.add(name)
		dict[name]=email
	except NameExist:
		print("Exception occurred: Name already exist")
	except AgeInvalid:
		print("Exception occurred: Invalid Age")
	except AgeUnder16:
		print("Exception occurred: Age is under 16")
	except InvalidEmail:
		print("Exception occurred: Invalid Email")
print("Valid Users are::")
for name,email in dict.items():
    print(name,"-->",email)