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


with open('day08.data') as file:
    data = file.read()
    total = 0
    for nr, line in enumerate(data.split('\n')):
        if len(line) != 0:
            total += calcLine(line)

print('part 1:', total)

# 1345 is too high
# 1342 is right
# 1340 is too low
