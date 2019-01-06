# coding: utf-8
data = open('day01.txt','r').read().replace('\n','')

def calcCaptcha(data):
    '''
    Part One of Day01 of aoc 2017
    '''
    captcha = 0

    for index in range(len(data)):
 
        try:
            if data[index] == data[index+1]:
                captcha += int(data[index])
        except:
            #last char, check with first char
            if data[index] == data[0]:
                captcha += int(data[index])

    return captcha

assert calcCaptcha('1122') == 3
assert calcCaptcha('1111') == 4
assert calcCaptcha('1234') == 0

print('Part One, result:', calcCaptcha(data))

def calcCaptcha2(data):
    '''
    Part Two of Day01 of aoc 2017
    '''
    captcha = 0
    dataHalfLength = int(len(data)/2)
    dataDouble = data*2
    for index in range(len(data)):
        if data[index] == dataDouble[index+dataHalfLength]:
            captcha += int(data[index])
    return captcha

assert calcCaptcha2('1212') == 6
assert calcCaptcha2('123123') == 12

print('Part Two, result:', calcCaptcha2(data))
