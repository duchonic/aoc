def lookAndSay(number):
    result = ""
    lastDigit = number[0]
    digitCount = 1
    for index in range(1, len(number)):
        digit = number[index]
        if digit == lastDigit:
            digitCount += 1
        else:
            result += str(digitCount)
            digitCount = 1
            result += lastDigit
        lastDigit = digit

    result += str(digitCount)
    result += lastDigit

    return result


assert lookAndSay('11') == '21'
assert lookAndSay('11') == '21'
assert lookAndSay('21') == '1211'
assert lookAndSay('1211') == '111221'
assert lookAndSay('111221') == '312211'

start = '3113322113'
for _ in range(50):
    start = lookAndSay(start)
    print(_, len(start))
print('result part 1:', len(start))
