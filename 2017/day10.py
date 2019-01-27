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

    mData = mData[mDataIndex:mDataIndex+256]

    return mData, hashit.indexTotal


dataOutput = [i for i in range(256)]
dataInput = [227, 169, 3, 166, 246, 201, 0, 47, 1, 255, 2, 254, 96, 3, 97, 144]


for i in range(len(dataInput)):
    dataOutput, indexTot = hashit(dataOutput, dataInput[i])
    print(dataOutput, indexTot % 5)

dataOutput = dataOutput * 2
dataOutput = dataOutput[256-indexTot % 256:256-indexTot % 256+256]

print('result part 1:', dataOutput[0]*dataOutput[1])
