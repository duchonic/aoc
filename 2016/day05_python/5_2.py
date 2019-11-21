import hashlib

def naturals(i=0):
	while True:
		yield i
		i += 1

def md5(str):
	return hashlib.md5(str.encode()).hexdigest()

hard_password = ['-'] * 8

for i in naturals():
    hash = md5("wtnhxymk" + str(i))

    if hash[:5] == '00000':
        index = hash[5]
        if index not in '01234567':
            continue

        index = int(index)
        if hard_password[index] != '-':
            continue

        hard_password[index] = hash[6]

    if not(any(c == '-' for c in hard_password)):
        break

print(hard_password)

