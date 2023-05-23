import re
def valid(ph):
    pattern="^[6-9][0-9]{9}"

    x=re.search(pattern,ph)
    if x is not None:
        print("Its a valid phone number")
    else:
        print("Its not a valid phone number")

valid("45454545")
