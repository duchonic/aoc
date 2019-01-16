def hashit(data, len):
    mData = list(data)

    try:
        hashit.skipSize += 1
    except AttributeError:
        hashit.skipSize = 0

    flipData = list(mData[:len])
    flipData = flipData[::-1]

    mData = flipData + mData[len:]

    mData = mData*2
    mDataIndex = int(len+hashit.skipSize)

    try:
        hashit.indexTotal += mDataIndex
    except AttributeError:
        hashit.indexTotal = mDataIndex

    mData = mData[ mDataIndex : mDataIndex+256 ]

    return mData, hashit.indexTotal

testdata = [i for i in range(256)]
testinput = [227,169,3,166,246,201,0,47,1,255,2,254,96,3,97,144]

for i in range(len(testinput)):
    testdata, indexTot = hashit(testdata, testinput[i])
    print(testdata, indexTot%5)

testdata = testdata * 2
testdata = testdata[256-indexTot%256:256-indexTot%256+256]
print('result part 1:',testdata[0]*testdata[1])
