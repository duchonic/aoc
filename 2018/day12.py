#!/usr/bin/env python
# coding: utf-8


def checkPlant(input) -> str:
    for item in actionsRaw:
        if input == item[0:5]:
            return item[-1]
    return '.'


testRaw = ".##..##..####..#.#.#.###....#...#..#.#.#..#...#....##.#.#.#.#.#..######.##....##.###....##..#.####.#"


actionsRaw = """
.#... => #
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
..##. => .
""".split('\n')


def sumPlants(data, border, leftShifts):
    summe = 0
    index = leftShifts - border 
    for letter in data:
        if letter == '#':
            summe += index
        index += 1
    return summe


data = list()

border = 5 
borderRight = 60 

for x in range(border):
    data.append('.')

for letter in testRaw:
    data.append(letter)

for x in range(borderRight):
    data.append('.')

index = 0
summeOld = 0
sumPlant = 0
shiftOneLeft = 0

lastSum = 0


for index in range(1, 11):
  print(index)

for generation in range(1, 10_001):
  
    result = list()
    result.append('.')
    result.append('.')

    for i in range(len(data)-2):
        checkData = "".join(str(x) for x in data[i:i+5])
        result.append(checkPlant(checkData))

    data = dict()
    data = result.copy()
    
    for i in range(10):
      if data[i] != '.':
        break
      if i==9:
        data.pop(0)
        data.append('.')
        shiftOneLeft += 1

    if generation % 1000 == 0:    
      print("".join(str(x) for x in result), 'generation:', generation, ' shift:', shiftOneLeft, ' sum: ' , sumPlants(result, border, shiftOneLeft) , ' diff: ', sumPlants(result, border, shiftOneLeft)-lastSum )
      lastSum = sumPlants(result, border, shiftOneLeft)


genLeft = 50_000_000_000 - 10_000


print(genLeft)
print( (genLeft*55) + sumPlants(result, border, shiftOneLeft)) 
