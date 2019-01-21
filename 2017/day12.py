#mport pprint

testdata = """0 <-> 2
1 <-> 1
2 <-> 0, 3, 4
3 <-> 2, 4
4 <-> 2, 3, 6
5 <-> 6
6 <-> 4, 5""".split('\n')

readFile = open('data/day12.data', 'r')
testdata = readFile.read().split('\n')
print(testdata.pop(-1))


mTree = dict()

for line in testdata:
    mData = line.replace('<->','').replace(',','').split()
    #print(mData[0], len(mData))
    mTree[int(mData[0])] = list()
    for index in range(1,len(mData)):
        #print(mData[index])
        mTree[int(mData[0])].append(int(mData[index]))

#pp = pprint.PrettyPrinter(indent=2)
#pp.pprint(mTree)

for keys in mTree:
    print(str(keys) + ' ' + str(keys))

print('#')

for key in mTree:
    for node in mTree[key]:
        print(str(key) + ' ' + str(node))
        if mTree[node].count(key) != 0:
            mTree[node].pop(mTree[node].index(key))

#PART 2 201 WAS TO LOW
#PART 2 206 WAS TO HIGH
#part 2 203 was to LOW
#PART 2 204 is correct
