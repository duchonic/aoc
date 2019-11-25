import hashlib

def naturals(i=0):
	while True:
		yield i
		i += 1

def md5(str):
	return hashlib.md5(str.encode()).hexdigest()


#print( md5("123") )
password = ''

for i in naturals():
    hash = md5("wtnhxymk" + str(i))

    if hash[:5] == '00000':
        password += hash[5]

    if len(password) == 8:
        break

print(password)
