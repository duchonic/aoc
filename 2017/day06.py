# coding: utf-8
def memoryAlloc(data):
    memory = list()
    newdata = data.split()
    newdata = [int(i) for i in newdata]
    turns = 0
    while 1:
        if memory.count(newdata) == 0:
            memory.append(list(newdata))
            max_ = 0
            for nr in newdata:
                if max_ < int(nr):
                    max_ = int(nr)
            indexMax = newdata.index(max_)      
            newdata[indexMax] = 0
            for i in range(indexMax+1,indexMax+max_+1):
                index = i%len(newdata)
                newdata[index] = int(newdata[index])+1    
            turns += 1
        else:
            print(newdata)
            break
    return memory, turns
