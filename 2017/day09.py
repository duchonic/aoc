# groups { , , { , , } , }
# garbage < , ,  >


def removeSpecial(data):
    mData = str(data)

    clearedChars = 0
    for index in range(len(mData)):
        if mData[index-clearedChars] == '!':
            mData = mData[0:index-clearedChars] + mData[index-clearedChars+2:]
            clearedChars += 2
    return mData, clearedChars

def removeGarbage(data):
    mData = str(data)
    clearGarbage = 0
    clearedChars = 0
    garbageCounter = 0

    for index in range(len(mData)):
        if mData[index-clearedChars] == '<':
            clearGarbage = 1
        if clearGarbage:
            if mData[index-clearedChars] == '>':
                clearGarbage = 0
                garbageCounter -= 2
            mData = mData[0:index-clearedChars] + mData[index-clearedChars+1:]
            clearedChars += 1
            garbageCounter += 1


    print('garbageCounter (result part 2)', garbageCounter)
    return mData, clearedChars

def checkGarbage(data):

    mData, mClearedChars = removeSpecial(data)
    print(mData)

    assert mData[0] == '<'
    assert mData[-1] == '>'

    return mData.replace('<', '').replace('>','')

def checkGroups(data):
    mData, mClearedChars = removeSpecial(data)
    print('special:', mClearedChars)
    mData, mClearedChars = removeGarbage(mData)
    print('garbage:', mClearedChars)


    assert mData[0] == '{'
    assert mData[-1] == '}'

    mData = ' ' + mData + ' '

    group = 1
    score = 1

    mData = mData.replace(',','')
    print(mData)
    for index in range(len(mData)):
        #if mData[index] == '{' and mData[index-1] == ',':
            #print('next item')
        if mData[index] == '{' and mData[index-1] == '{':
            #print('plus one group')
            group += 1
        elif mData[index] == '}' and mData[index+1] == '{':
            #print('end item')
            score += group
        elif mData[index] == '}' and mData[index+1] == '}':
            #print('end group')
            score += group
            group -= 1
    return score

assert checkGarbage('<>') == ''
assert checkGarbage('<xd>') == 'xd'
assert checkGarbage('<<<<>') == ''
assert checkGarbage('<{!>}>') == '{}'
assert checkGarbage('<!!>') == ''
assert checkGarbage('<!!!>>') == ''
assert checkGarbage('<{o"i!a,<{i<a>') == '{o"i,{ia'

assert checkGroups('{}') == 1
assert checkGroups('{{{}}}') == 6
assert checkGroups('{{},{}}') == 5
assert checkGroups('{{{},{},{{}}}}') == 16
assert checkGroups('{<a>,<a>,<a>,<a>}') == 1
assert checkGroups('{{<ab>},{<ab>},{<ab>},{<ab>}}') == 9
assert checkGroups('{{<!!>},{<!!>},{<!!>},{<!!>}}') == 9
assert checkGroups('{{<a!>},{<a!>},{<a!>},{<ab>}}') == 3

print('check test')
checkGroups('{<{o"i!a,<{i<a>}')
print('end test')

data = open('day09.data','r').read()
print('result part 1:', checkGroups(data[:-1]))

# 17283 is to high

#part 2 8103 was to high
#part 2 5334 is to low
#part 2 6671 is ok
