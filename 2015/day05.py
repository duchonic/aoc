# coding: utf-8
# %load day05.py
def checkPairs(data):
    if data.find('ab') != -1:
        return 1
    elif data.find('cd') != -1:
        return 1
    elif data.find('pq') != -1:
        return 1
    elif data.find('xy') != -1:
        return 1
    else:
        return 0
    
def checkDoubles(data):
    oldChar = 0
    for char in data:
        if char == oldChar:
            return 1
        else:
            oldChar = char
    return 0
def countVowels(data):
    return data.count('a')+data.count('e')+data.count('i')+data.count('o')+data.count('u')
goodLine = 0
for line in data:
    if (checkPairs(line) == 0) and (checkDoubles(line) == 1) and (countVowels(line) >= 3):
        goodLine += 1
        print(line)
print(goodLine)
