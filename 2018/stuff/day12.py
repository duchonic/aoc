testRaw = ".##..##..####..#.#.#.###....#...#..#.#.#..#...#....##.#.#.#.#.#..######.##....##.###....##..#.####.#"
actionsRaw = """.#... => #
#.... => .
#.### => .
#.##. => .
#...# => .
...#. => .
.#..# => #
.#### => #
.###. => .
###.. => #
##### => .
....# => .
.#.## => #
####. => .
##.#. => #
#.#.# => #
..#.# => .
.#.#. => #
###.# => #
##.## => .
..#.. => .
..... => .
..### => #
#..## => #
##... => #
...## => #
##..# => .
.##.. => #
#..#. => .
#.#.. => #
.##.# => .
..##. => .""".split('\n')

data = list()

border = 5
borderRight = 220

for blub in range(border):
    data.append('.')

for letter in testRaw:
    data.append(letter)

for blub in range(borderRight):
    data.append('.')


def checkPlant(input) -> str:
    for item in actionsRaw:
        if input == item[0:5]:
            return item[-1]
    return '.'

def sumPlants(data,border):
    index = -border
    summe = 0
    for letter in data:
        if letter == '#':
            summe += index
            #print('index: ', index, 'letter:', letter, 'summe:', summe, 'diff:', summe)
        index += 1
    return summe

index = 0
summeOld = 0
sumPlant = 0

sumOfGenerations = 200

print('inputdata', data)
for item in actionsRaw:
    print('actionsRaw', item)

for generations in range(sumOfGenerations):
    result = list()
    result.append('.')
    result.append('.')
    for i in range(len(data)-2):
        checkData = "".join(str(x) for x in data[i:i+5])
        result.append(checkPlant(checkData))

    data = dict()
    data = result.copy()
    print("".join(str(x) for x in result ))
    sumPlant = sumPlants(data, border)
    print('gen:',generations, 'sumPlant:', sumPlant, 'diff:', sumPlant - summeOld)
    summeOld = sumPlant

print(sumOfGenerations,'generation has', sumPlant, 'plants')
generationsLeft = 50000000000 - sumOfGenerations
print('generations left:', generationsLeft)
totalPlants = (generationsLeft * 55)
print('plants left:', totalPlants)
print(totalPlants+sumPlant)
