# packet scanners

firewall = dict()

data = """0: 4
1: 2
2: 3
4: 4
6: 8
8: 5
10: 8
12: 6
14: 6
16: 8
18: 6
20: 6
22: 12
24: 12
26: 10
28: 8
30: 12
32: 8
34: 12
36: 9
38: 12
40: 8
42: 12
44: 17
46: 14
48: 12
50: 10
52: 20
54: 12
56: 14
58: 14
60: 14
62: 12
64: 14
66: 14
68: 14
70: 14
72: 12
74: 14
76: 14
80: 14
84: 18
88: 14""".split('\n')

# data = """0: 3
# 1: 2
# 4: 4
# 6: 4""".split('\n')

for line in data:
    arr = line.replace(':', '').split()
    firewall[int(arr[0])] = [0]*int(arr[1])
    firewall[int(arr[0])][0] = 1

print(firewall)

def scatter(data):
    for item in data:
        for entry in data[item]:
            if entry == 1:
                #shift right
                index = data[item].index(1)
                data[item][index] = 0
                index += 1
                if index+1 == len(data[item]):
                    data[item][index] = -1
                else:
                    data[item][index] = 1
                break
            if entry == -1:
                #shift left
                index = data[item].index(-1)
                data[item][index] = 0
                index -= 1
                if index == 0:
                    data[item][index] = 1
                else:
                    data[item][index] = -1
                break


for delay in range(1,5000):

    if delay%100 == 0:
        print(delay)

    for line in data:
        arr = line.replace(':', '').split()
        firewall[int(arr[0])] = [0]*int(arr[1])
        firewall[int(arr[0])][0] = 1

    for i in range(delay):
        scatter(firewall)

    severity = 0

    for i in range(89):
        try:
            if firewall[i][0] == 1:
                severity += i*len(firewall[i])
                severity = 1
                break
        except:
            pass
        scatter(firewall)

    found = 0
    for key, value in firewall.items():
        #print(key, value)
        if value[0] == 1:
            found += 1
    if found == len(firewall):
        print('found:', found, 'delay:', delay)
        break

    if severity == 0:
         print('result part 2:', delay)
         break
