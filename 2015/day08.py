import string


def calcLine(data):
    totalMinus = 0
    for index, char in enumerate(data):
        if char == '\\':
            if line[index+1] == '\\':
                pass
            if line[index-1] == '\\':
                pass
            elif line[index+1] == 'x':
                if not all(c in string.hexdigits
                           for c in line[index+2:index+4]):
                    print('index', index, line[index-4:index+6])
                else:
                    totalMinus += 3
            else:
                totalMinus += 1
    return len(data) - (len(data)-2-totalMinus)


def memoryString(data):
    memString = ""
    control = False
    hexValue = 0
    for index, char in enumerate(data):

        if control:
            control = False
            if char == 'x':
                hexValue = 2
                memString += 'X'
            else:
                memString += char
        elif char == '\\':
            control = True
        else:
            if hexValue > 0:
                hexValue -= 1
            else:
                memString += char
    return memString


def encodeString(data):
    additionalLen = len(data) + 4
    additionalLen += data.count('\\')
    additionalLen += data[1:-1].count('"')
    return additionalLen


with open('day08.data') as file:
    data = file.read()
    total = 0
    total2 = 0
    total3 = 0
    for nr, line in enumerate(data.split('\n')):
        if len(line) != 0:
            total += calcLine(line)
            total2 += len(line) - (len(memoryString(line))-2)
            total3 += encodeString(line) - len(line)

            print(line)
            print(encodeString(line))

print('part 1:', total)
print('part 1 solution 2:', total2)
print('part 2:', total3)

# 1345 is too high
# 1342 is right
# 1340 is too low

# part 2
# 2061 is too low
# 2090 is too high
# 2094 is too high
