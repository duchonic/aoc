import re

def count_maps(input):
    count = input.count("XMAS") + input.count("SAMX")
    print("count", count, " on input: ", input)
    return count

def read_file():
    
    map = []

    with open('day4.txt') as file:
        lines = file.readlines()
        for line in lines:
            map.append(line.strip())

    part1 = 0
    # check every line
    for y in map:
        part1 += count_maps(y)


    # check columns
    for x in range(len(map[0])):
        column = ""
        for y in range(len(map)):
            column += map[y][x]

        part1 += count_maps(column)

    # check diagonals left to right
    print("check diagonals")
    for x in range(len(map[0])):
        diagonal = ""
        for y in range(len(map)):
            if x + y < len(map[0]):
                diagonal += map[y][x + y]
        part1 += count_maps(diagonal)
    for x in range(1,len(map[0])):
        diagonal = ""
        for y in range(len(map)):
            try:
                if x + y < len(map[0]):
                    diagonal += map[x+y][y]
            except:
                pass
        part1 += count_maps(diagonal)



    # check diagonals right to left
    for x in range(len(map[0]) + len(map) - 1):
        diagonal = ""
        for y in range(len(map)):
            try:
                if x - y >= 0:
                    diagonal += map[y][x - y]
            except:
                pass

        part1 += count_maps(diagonal)

   

    return part1


def main():
    print("part1: ", read_file())


    
if __name__ == '__main__':
    main()